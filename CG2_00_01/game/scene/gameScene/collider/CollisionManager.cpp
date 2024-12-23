#include "CollisionManager.h"

#include <cmath>

#include "Vector2.h"

void CollisionManager::Reset()
{
    colliders_.clear();
}

void CollisionManager::AddCollider(Collider* collider)
{
    colliders_.push_back(collider);
}

void CollisionManager::CheckAllCollisions()
{
    std::list<Collider*>::iterator itrA = colliders_.begin();
    for (; itrA != colliders_.end(); ++itrA) {
        Collider* colliderA = *itrA;

        std::list<Collider*>::iterator itrB = itrA;
        itrB++;
        for (; itrB != colliders_.end(); ++itrB) {
            Collider* colliderB = *itrB;

            CheckCollisionPair(colliderA, colliderB);
        }
    }
}

void CollisionManager::CheckCollisionPair(Collider* colliderA, Collider* colliderB)
{
    Vector2 PosA = colliderA->GetCenterPosition();
    Vector2 PosB = colliderB->GetCenterPosition();
    Vector2 subtract = { PosB.x - PosA.x, PosB.y - PosA.y };

    float distance = std::sqrt(subtract.x * subtract.x + subtract.y * subtract.y);

    float radiusA = colliderA->GetRadius();
    float radiusB = colliderB->GetRadius();

    std::string nameA = colliderA->GetColliderName();
    std::string nameB = colliderB->GetColliderName();

    // 衝突の判定
    if (distance <= (radiusA + radiusB) && nameA != nameB) {
        colliderA->OnCollision();
        colliderB->OnCollision();
    }
}