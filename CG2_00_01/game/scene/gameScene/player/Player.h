#pragma once

#include <memory>
#include <list>

#include "Sprite.h"

#include "state/BaseState.h"
#include "bullet/PlayerBullet.h"

class Player
{
public:

	void Init();

	void Update();

	void Draw();

	// 状態遷移をチェンジ
	void ChangeState(std::unique_ptr<BaseState> newState);

	// プレイヤーのSpriteを取得
	Sprite* GetSprite()const { return sprite_.get(); }

	// プレイヤーの弾を取得
	const std::list<std::unique_ptr<PlayerBullet>>& GetBullets() const {
		return bullets_;
	}

	// プレイヤーの弾をセット
	void SetBullet();

	float GetDamageCount() { return ++damageCount_; }

private:

	std::unique_ptr<Sprite> sprite_ = nullptr;
	std::list<std::unique_ptr<PlayerBullet>> bullets_;
	float damageCount_ = 0;

	std::unique_ptr<BaseState> state_ = nullptr;
};