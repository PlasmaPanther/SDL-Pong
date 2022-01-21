#pragma once
#include <cmath>

struct Vector2 {
	float x, y;
	
	Vector2(float _x = 0.0f, float _y = 0.0f) {
		x = _x;
		y = _y;
	}

	Vector2& operator += (const Vector2& rightside) {
		
		x += rightside.x;
		y += rightside.y;

		return *this;
	}

	Vector2& operator -= (const Vector2& leftside) {

		x -= leftside.x;
		y -= leftside.y;

		return *this;
	}

};

inline Vector2 operator +(const Vector2& leftside, const Vector2& rightside) {
	return Vector2(leftside.x + rightside.x, leftside.y + rightside.y);
}

inline Vector2 operator -(const Vector2& leftside, const Vector2& rightside) {
	return Vector2(leftside.x - rightside.x, leftside.y - rightside.y);
}

inline Vector2 operator *(const Vector2& leftside, const float& rightside) {
	return Vector2(leftside.x * rightside, leftside.y * rightside);
}

inline Vector2 operator *(const float& leftside, const Vector2& rightside) {
	return Vector2(leftside * rightside.x, leftside * rightside.y);
}

inline Vector2 operator /(const Vector2& leftside, const float& rightside) {
	return Vector2(leftside.x / rightside, leftside.y / rightside);
}

inline Vector2 operator /(const float& leftside, const Vector2& rightside) {
	return Vector2(leftside / rightside.x, leftside / rightside.y);
}