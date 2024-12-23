#include "Player.h"

#include "SceneManager.h"

#include "gameScene/player/state/MoveState.h"

void Player::Init()
{
	sprite_ = std::make_unique<Sprite>();
	sprite_->Initialize("uvChecker.png");
	sprite_->SetAnchorPoint({ 0.5f,0.5f });
	sprite_->SetSize({ 96.0f,96.0f });
	sprite_->SetPosition({ 640.0f,600.0f });

	ChangeState(std::make_unique<MoveState>(this));
}

void Player::Update()
{
	state_->Update();

	sprite_->Update();

	for (auto& bullet : bullets_) {
		bullet->Update();
	}
	bullets_.remove_if([](const std::unique_ptr<PlayerBullet>& bullet) {
		return !bullet->GetIsActive();
	});

	if (damageCount_ >= 3) {
		SceneManager::GetInstance()->ChangeScene("Clear");
	}
}

void Player::Draw()
{
	state_->Draw();

	for (auto& bullet : bullets_) {
		bullet->Draw();
	}

	sprite_->Draw();
}

void Player::ChangeState(std::unique_ptr<BaseState> newState)
{
	state_ = std::move(newState);
	state_->Initialize();
}

void Player::SetBullet()
{
	std::unique_ptr<PlayerBullet> bullet = std::make_unique<PlayerBullet>();
	bullet->Init(sprite_->GetPosition());
	bullet->SetPlayer(this);
	bullets_.push_back(std::move(bullet));
}
