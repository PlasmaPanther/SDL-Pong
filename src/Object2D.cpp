#include "Object2D.h"
#include <iostream>

Object2D::Object2D(float x, float y) {

    _Vector2.x = x;
    _Vector2.y = y;

    object_rect = { 0, 0, 0, 0 };
    object_rectSrc = { 0, 0, 0, 0 };

	animated_object_destRect = { 0, 0, 0, 0 };
	animated_object_srcRect = { 0, 0, 0, 0 };

}

void Object2D::Move(Vector2 _vec){
	object_rect.x += (int)_vec.x;
	object_rect.y += (int)_vec.y;
}

void Object2D::MoveAnimated(Vector2 _vec) {
    animated_object_destRect.x += (int)_vec.x;
    animated_object_destRect.y += (int)_vec.y;
}

bool Object2D::CheckCollision(SDL_Rect* recta, SDL_Rect* rectb)
{
    if (SDL_HasIntersection(recta, rectb)) {
        return true;
    }

    return false;
}

SDL_Rect* Object2D::GetRect()
{
	return &object_rect;
}

SDL_Rect* Object2D::GetAnimatedRect()
{
    return &animated_object_destRect;
}


//=============== Test functions; Ignore for now =============================
void Object2D::Event(const SDL_Event& e) {
    int16_t mouse_X, mouse_Y;

    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN)
    {
        //Get the mouse offsets
        mouse_X = e.motion.x;
        mouse_Y = e.motion.y;

        if (e.button.button == SDL_BUTTON_LEFT) {
            mouse_X = e.button.x; //Gets the x pos of the mouse where the left click happend
            mouse_Y = e.button.y;

            //If the mouse is over the button
            if ((mouse_X > object_rect.x) && (mouse_X < object_rect.x + object_rect.w) && (mouse_Y > object_rect.y) && (mouse_Y < object_rect.y + object_rect.h))
            {
                printf("clicked\n");
                // Places the center of the rect on the cursor
                object_rect.x = mouse_X - object_rect.w / 2;
                object_rect.y = mouse_Y - object_rect.h / 2;

            }
        }
    }
}

void Object2D::animatedEvent(const SDL_Event& e) {
    int16_t mouse_X, mouse_Y;

    if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN)
    {
        //Get the mouse offsets
        mouse_X = e.motion.x;
        mouse_Y = e.motion.y;

        if (e.button.button == SDL_BUTTON_LEFT) {
            mouse_X = e.button.x; //Gets the x pos of the mouse where the left click happend
            mouse_Y = e.button.y;

            //If the mouse is over the button
            if ((mouse_X > animated_object_destRect.x) && (mouse_X < animated_object_destRect.x + animated_object_destRect.w) && (mouse_Y > animated_object_destRect.y) && (mouse_Y < animated_object_destRect.y + animated_object_destRect.h))
            {
                // Places the center of the rect on the cursor
                animated_object_destRect.x = mouse_X - animated_object_destRect.w / 2;
                animated_object_destRect.y = mouse_Y - animated_object_destRect.h / 2;

            }
        }
    }
}