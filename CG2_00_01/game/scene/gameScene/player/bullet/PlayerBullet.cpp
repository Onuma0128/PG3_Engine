#include "PlayerBullet.h"

#include "gameScene/player/Player.h"

void PlayerBullet::OnCollision()
{
	isActive_ = false;
	player_->GetDamageCount();
}

Vector2 PlayerBullet::GetCenterPosition() const
{
	return sprite_->GetPosition();
}

std::string PlayerBullet::GetColliderName() const
{
	return "bullet";
}

float PlayerBullet::GetRadius() const
{
	return 16.0f;
}

void PlayerBullet::Init(Vector2 position)
{
	sprite_ = std::make_unique<Sprite>();
	sprite_->Initialize("uvChecker.png");
	sprite_->SetAnchorPoint({ 0.5f,0.5f });
	sprite_->SetSize({ 32.0f,32.0f });
	sprite_->SetPosition(position);

	isActive_ = true;
}

void PlayerBullet::Update()
{
	if (!isActive_) {
		return;
	}

	activeFrame_ += 1.0f / 120.0f;
	if (activeFrame_ >= 1.0f) {
		isActive_ = false;
	}

	Vector2 position = sprite_->GetPosition();
	const float kSpeed = 10.0f;

	position.y -= kSpeed;
	sprite_->SetPosition(position);

	sprite_->Update();
}

void PlayerBullet::Draw()
{
	if (!isActive_) {
		return;
	}

	sprite_->Draw();
}
