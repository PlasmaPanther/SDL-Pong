#include <algorithm>

#include "CollisionManager.h"
#include "Shape2D.h"

CollisionManager::~CollisionManager()
{
    EmptyCollisionContainer();
}

void CollisionManager::AddCollider(Object2D* collider, const std::string& identifier)
{
    s_ColliderContainer.push_back(std::make_pair(collider, identifier));

    s_IsColliding.push_back("");
}

void CollisionManager::AddCollider(Shape2D* collider, const std::string& identifier)
{
    s_ShapeContainer.push_back(std::make_pair(collider, identifier));
    
    s_IsColliding.push_back("");
}

void CollisionManager::IgnoreCollider(const std::string& identifier)
{
    s_IgnoredColliders.push_back(identifier);
}

void CollisionManager::Update()
{

    if (s_ColliderContainer.size() > 1) {

        for (int i = 0; i < s_ColliderContainer.size(); ++i) {

            for (int j = 0; j < s_ColliderContainer.size(); ++j) {

                //Rectangular Collision with objects (E.g. textures)
                if (CheckCollison(s_ColliderContainer[i].first, s_ColliderContainer[i].second, s_ColliderContainer[j].first, s_ColliderContainer[j].second)) {

                    s_IsColliding[i] = s_ColliderContainer[i].second; //assign the colliding identifier

                    s_IsColliding[j] = s_ColliderContainer[j].second;

                    return; //exit function
                }
                else {

                    s_IsColliding[i] = ""; //remove assigned identifier if not colliding

                    s_IsColliding[j] = "";
                }

            }

            for (int k = 0; k < s_ShapeContainer.size(); ++k) {

                //Rectangular Collision (primitives and textures)
                if (CheckCollison(s_ColliderContainer[i].first, s_ColliderContainer[i].second, s_ShapeContainer[k].first, s_ShapeContainer[k].second)) {
                    
                    s_IsColliding[i] = s_ColliderContainer[i].second;

                    if (!s_IsColliding[k].empty()) { //check if value is present at current index

                        s_IsColliding[k + 1] = s_ShapeContainer[k].second; //if there is assign it to the next one

                    }
                    else {
                        s_IsColliding[k] = s_ShapeContainer[k].second; //if not proceed as normal
                    }

                    return;
                }
                //Rectangular & Circular Collision (primitives and textures)
                else if (CheckCircleToRectCollision(s_ShapeContainer[k].first, s_ShapeContainer[k].second, s_ColliderContainer[i].first, s_ColliderContainer[i].second)) {

                    s_IsColliding[i] = s_ColliderContainer[i].second;

                    if (!s_IsColliding[k].empty()) {

                        s_IsColliding[k + 1] = s_ShapeContainer[k].second;

                    }
                    else {
                        s_IsColliding[k] = s_ShapeContainer[k].second;
                    }

                    return;

                }
                else {

                    s_IsColliding[i] = "";

                    s_IsColliding[k] = "";

                }

            }

        }

    }

    if (s_ShapeContainer.size() > 1) {

        for (int i = 0; i < s_ShapeContainer.size(); ++i) {

            for (int j = 0; j < s_ShapeContainer.size(); ++j) {

                //Rectangular Collision (primitives)
                if (CheckCollison(s_ShapeContainer[i].first, s_ShapeContainer[i].second, s_ShapeContainer[j].first, s_ShapeContainer[j].second)) {
                    
                    s_IsColliding[i] = s_ShapeContainer[i].second;

                    s_IsColliding[j] = s_ShapeContainer[j].second;

                    return;

                }
                //Circular Collision (primitives)
                else if (CheckCircleCollision(s_ShapeContainer[i].first, s_ShapeContainer[i].second, s_ShapeContainer[j].first, s_ShapeContainer[j].second)){

                    s_IsColliding[i] = s_ShapeContainer[i].second;

                    s_IsColliding[j] = s_ShapeContainer[j].second;

                    return;

                }
                //Rectangular & Circular Collision (primitives)
                else if (CheckCircleToRectCollision(s_ShapeContainer[i].first, s_ShapeContainer[i].second, s_ShapeContainer[j].first, s_ShapeContainer[j].second)) {

                    s_IsColliding[i] = s_ShapeContainer[i].second;

                    s_IsColliding[j] = s_ShapeContainer[j].second;

                    return;

                }
                else {

                    s_IsColliding[i] = "";

                    s_IsColliding[j] = "";

                }
            }

        }
    }

}

bool CollisionManager::CheckGroupCollision(const std::string& IdentifierA, const std::string& IdentifierB)
{
   
    if (IdentifierA != IdentifierB && ShouldCollide(IdentifierA, IdentifierB)) {

        auto identifierA = std::find(s_IsColliding.begin(), s_IsColliding.end(), IdentifierA);
        auto identifierB = std::find(s_IsColliding.begin(), s_IsColliding.end(), IdentifierB);

        if (identifierA != s_IsColliding.end() && identifierB != s_IsColliding.end()) {
            
            for (auto& id : s_IsColliding) {

                id = ""; //remove assigned identifier to avoid unnecessary collisions
            }

            return true;
        }

    }

    return false;
}

bool CollisionManager::ShouldCollide(const std::string& identifierA, const std::string& identifierB)
{
   
    auto ignoredIdentifierA = std::find(s_IgnoredColliders.begin(), s_IgnoredColliders.end(), identifierA);
    auto ignoredIdentifierB = std::find(s_IgnoredColliders.begin(), s_IgnoredColliders.end(), identifierB);

    if (ignoredIdentifierA != s_IgnoredColliders.end() && ignoredIdentifierB != s_IgnoredColliders.end()) {

        return false; //if these colliders are in the vector then collision between them shouldn't happen 
    }

    return true;
}

bool CollisionManager::CheckCollison(Object2D* colliderA, const std::string& identifierA, Object2D* colliderB, const std::string& identifierB)
{

    if (identifierA != identifierB && ShouldCollide(identifierA, identifierB)) {

        SDL_FRect RectA = colliderA->GetRect();
        SDL_FRect RectB = colliderB->GetRect();

        //sometimes when no rects are used the collision check ends up as true because the width and height are zero
        if (RectA.w > 0 && RectB.w > 0) { //this prevents from "false positives" to occur

            if (RectA.x + RectA.w >= RectB.x && RectB.x + RectB.w >= RectA.x && RectA.y + RectA.h >= RectB.y && RectB.y + RectB.h >= RectA.y) {

                return true;
            }

        }

    }

    return false;
}

bool CollisionManager::CheckCollison(Object2D* colliderA, const std::string& identifierA, Shape2D* colliderB, const std::string& identifierB)
{

    if (colliderB != nullptr) {

        //convert Shape2D object to Object2D
        Object2D* ColliderB = static_cast<Object2D*>(colliderB);

        return CheckCollison(colliderA, identifierA, ColliderB, identifierB);

    }

    return false;
}

bool CollisionManager::CheckCollison(Shape2D* colliderA, const std::string& identifierA, Shape2D* colliderB, const std::string& identifierB)
{
    if (colliderB != nullptr) {

        //convert Shape2D object to Object2D
        Object2D* ColliderB = static_cast<Object2D*>(colliderB);

        return CheckCollison(colliderA, identifierA, ColliderB, identifierB);

    }

    return false;
}

bool CollisionManager::CheckCircleCollision(Shape2D* colliderA, const std::string& identifierA, Shape2D* colliderB, const std::string& identifierB)
{

    if (identifierA != identifierB && ShouldCollide(identifierA, identifierB)) {

        if (colliderA->GetCircle().radius > 0 && colliderB->GetCircle().radius > 0) {

            Circle circlea = colliderA->GetCircle();
            Circle circleb = colliderB->GetCircle();

            float deltaX = circlea.x - circleb.x;
            float deltaY = circlea.y - circleb.y;

            float distance = sqrtf(deltaX * deltaX + deltaY * deltaY);

            float totalRadius = circlea.radius + circleb.radius;

            if (distance < totalRadius) {

                return true;
            }
        }

    }

    return false;
}

bool CollisionManager::CheckCircleToRectCollision(Shape2D* colliderA, const std::string& identifierA, Shape2D* colliderB, const std::string& identifierB)
{

    if (colliderB != nullptr) {

        Object2D* ColliderB = static_cast<Object2D*>(colliderB);

        return CheckCircleToRectCollision(colliderA, identifierA, ColliderB, identifierB);

    }

    return false;
}

bool CollisionManager::CheckCircleToRectCollision(Shape2D* colliderA, const std::string& identifierA, Object2D* colliderB, const std::string& identifierB)
{
    if (identifierA != identifierB && ShouldCollide(identifierA, identifierB)) {

        Circle _circle = { 0, 0, 0 };
        SDL_FRect rect = { 0, 0, 0, 0 };

        if (colliderA->GetCircle().radius > 0) { //if radius is bigger than zero
            _circle = colliderA->GetCircle(); //this means a circle collider is present
        }
        else {
            rect = colliderA->GetRect(); //if not then rect is used
        }

        if (colliderB->GetRect().w > 0 && colliderB->GetRect().h > 0) { //if dimensions are big enough then a rect is used
            rect = colliderB->GetRect();
        }
        else {
            Shape2D* ColliderB; //if not then a circle should be used

            ColliderB = static_cast<Shape2D*>(colliderB); //convert Object2D to Shape2D
            _circle = ColliderB->GetCircle();

            ColliderB = nullptr;
        }

        //Collision check happens here
        if (_circle.radius > 0 && rect.w > 0) {
            float testX = _circle.x;
            float testY = _circle.y;

            //which edge is closår
            if (_circle.x < rect.x) {
                testX = rect.x; //test left edge
            }
            else if (_circle.x > rect.x + rect.w) {
                testX = rect.x + rect.w; //right edge
            }

            if (_circle.y < rect.y) {
                testY = rect.y; //top edge
            }
            else if (_circle.y > rect.y + rect.h) {
                testY = rect.y + rect.h; //bottom edge
            }

            //get distance from the closest edges
            float distanceX = _circle.x - testX;
            float distanceY = _circle.y - testY;

            float distance = sqrtf((distanceX * distanceX) + (distanceY * distanceY));

            //if the distance is less than the radius
            if (distance <= _circle.radius) {

                colliderA = nullptr;
                colliderB = nullptr;

                return true;
            }

            colliderA = nullptr;
            colliderB = nullptr;
        }
    }

    return false;
}

void CollisionManager::RemoveCollider(const std::string& identifier)
{

    if (s_ColliderContainer.size() > 1) {

        for (int i = 0; i < s_ColliderContainer.size(); ++i) {

            if (s_ColliderContainer[i].second == identifier) {

                s_ColliderContainer.erase(std::remove(s_ColliderContainer.begin(), s_ColliderContainer.end(), s_ColliderContainer[i]));

                i = 0;

                //the reason the index is reset because otherwise it will iterate through the entire vector while skiping elements that need to be removed
                //the erased element gets removed from the container while the next one takes its place and gets skipped
            }
        }

        s_ColliderContainer.shrink_to_fit();
    }
}

void CollisionManager::RemoveIgnoredCollider(const std::string& identifier)
{
    s_IgnoredColliders.erase(std::remove(s_IgnoredColliders.begin(), s_IgnoredColliders.end(), identifier), s_IgnoredColliders.end());
    s_IgnoredColliders.shrink_to_fit();
}

void CollisionManager::EmptyCollisionContainer()
{
    s_ColliderContainer.clear();
    s_ColliderContainer.shrink_to_fit();

    s_IsColliding.clear();
    s_IsColliding.shrink_to_fit();

    s_ShapeContainer.clear();
    s_IsColliding.shrink_to_fit();
}

SDL_FRect& CollisionManager::GetCollider(const std::string& identifier)
{
    //Search container for specified identifier
    auto it = std::find_if(s_ColliderContainer.begin(), s_ColliderContainer.end(), [&](const std::pair<Object2D*, std::string>& element) { return element.second == identifier; });
    int position = 0;

    if (it != s_ColliderContainer.end()) {

        position = it - s_ColliderContainer.begin(); //calculate position of the identifier

    }

    return s_ColliderContainer.at(position).first->GetRect();
}

SDL_FRect& CollisionManager::GetPrimitiveRectCollider(const std::string& identifier)
{
    //Search container for specified identifier
    auto it = std::find_if(s_ShapeContainer.begin(), s_ShapeContainer.end(), [&](const std::pair<Shape2D*, std::string>& element) { return element.second == identifier; });
    int position = 0;

    if (it != s_ShapeContainer.end()) {

        position = it - s_ShapeContainer.begin(); //calculate position of the identifier

    }

    return s_ShapeContainer.at(position).first->GetRect();
}

Circle& CollisionManager::GetPrimitiveCircleCollider(const std::string& identifier)
{
    //Search container for specified identifier
    auto it = std::find_if(s_ShapeContainer.begin(), s_ShapeContainer.end(), [&](const std::pair<Shape2D*, std::string>& element) { return element.second == identifier; });
    int position = 0;

    if (it != s_ShapeContainer.end()) {

        position = it - s_ShapeContainer.begin(); //calculate position of the identifier

    }

    return s_ShapeContainer.at(position).first->GetCircle();
}
