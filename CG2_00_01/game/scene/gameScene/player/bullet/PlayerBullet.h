#pragma once

#include <memory>

#include "Sprite.h"
#include "Vector2.h"

#include "gameScene/collider/Collider.h"

class Player;

class PlayerBullet : public Collider
{
public:

	// 当たり判定
	void OnCollision()override;
	Vector2 GetCenterPosition() const override;
	std::string GetColliderName() const override;
	float GetRadius()const override;


	void Init(Vector2 position);

	void Update();

	void Draw();

	bool GetIsActive()const { return isActive_; }

	void SetPlayer(Player* player) { player_ = player; }

private:

	Player* player_ = nullptr;

	std::unique_ptr<Sprite> sprite_ = nullptr;

	bool isActive_ = true;
	float activeFrame_ = 0.0f;

};