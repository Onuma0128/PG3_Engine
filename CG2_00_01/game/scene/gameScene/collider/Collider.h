#pragma once
#include <string>

#include "Vector2.h"

class Collider
{
public:

	virtual ~Collider() = default;
	virtual void OnCollision() {}
	virtual Vector2 GetCenterPosition() const = 0;
	virtual std::string GetColliderName()const = 0;
	virtual float GetRadius()const = 0;

};