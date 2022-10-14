#pragma once
#include <vector>
#include <utility>
#include <string>
#include "Shape2D.h"

class CollisionManager
{
public:

	~CollisionManager();

	static void AddCollider(Object2D* collider, const std::string& identifier);
	static void AddCollider(Shape2D* collider, const std::string& identifier);

	static void IgnoreCollider(const std::string& identifier);

	static void Update();

	//Checks if selected groups are colliding with each other
	static bool CheckGroupCollision(const std::string& identifierA, const std::string& identifierB);

	static void RemoveCollider(const std::string& identifier);
	static void RemoveIgnoredCollider(const std::string& identifier);

	static void EmptyCollisionContainer();

	static SDL_FRect& GetCollider(const std::string& identifier);
 
	static SDL_FRect& GetPrimitiveRectCollider(const std::string& identifier);
	static Circle& GetPrimitiveCircleCollider(const std::string& identifier);

private:

	//Checks to see if selected groups are supposed to collide with each other by comparing identifiers
	static bool ShouldCollide(const std::string& identifierA, const std::string& identifierB);

	//Checks collision between 2 rectangles
	static bool CheckCollison(Object2D* colliderA, const std::string& identifierA, Object2D* colliderB, const std::string& identifierB);
	static bool CheckCollison(Object2D* colliderA, const std::string& identifierA, Shape2D* colliderB, const std::string& identifierB);
	static bool CheckCollison(Shape2D* colliderA, const std::string& identifierA, Shape2D* colliderB, const std::string& identifierB);

	//Checks collision between 2 circles
	static bool CheckCircleCollision(Shape2D* colliderA, const std::string& identifierA, Shape2D* colliderB, const std::string& identifierB);

	//Checks collision between a circle and rectangle
	static bool CheckCircleToRectCollision(Shape2D* colliderA, const std::string& identifierA, Shape2D* colliderB, const std::string& identifierB);
	static bool CheckCircleToRectCollision(Shape2D* colliderA, const std::string& identifierA, Object2D* colliderB, const std::string& identifierB);

private:

	static inline std::vector<std::pair<Object2D*, std::string>> s_ColliderContainer;

	static inline std::vector<std::pair<Shape2D*, std::string>> s_ShapeContainer;

	static inline std::vector<std::string> s_IsColliding;

	static inline std::vector<std::string> s_IgnoredColliders;

};

