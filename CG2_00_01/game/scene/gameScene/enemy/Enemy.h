#pragma once

#include <memory>

#include "Sprite.h"
#include "Vector2.h"

#include "gameScene/enemy/state/EnemyBaseState.h"
#include "gameScene/collider/Collider.h"

class Enemy : public Collider
{
public:

	// 当たり判定
	void OnCollision()override;
	Vector2 GetCenterPosition() const override;
	std::string GetColliderName() const override;
	float GetRadius()const override;


	void Init(const Vector2& position);

	void Update();

	void Draw();

	// 状態遷移をチェンジ
	void ChangeState(std::unique_ptr<EnemyBaseState> newState);

	// 敵のSpriteを取得
	Sprite* GetSprite()const { return sprite_.get(); }

	bool GetIsActive()const { return isActive_; }
	void SetIsActive(bool isActive) { isActive_ = isActive; }

private:
	std::unique_ptr<Sprite> sprite_ = nullptr;
	bool isActive_ = true;

	std::unique_ptr<EnemyBaseState> state_ = nullptr;
};