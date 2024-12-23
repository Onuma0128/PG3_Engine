#include "Enemy.h"

#include "state/EnemyMoveState.h"

void Enemy::OnCollision()
{
	isActive_ = false;
}

Vector2 Enemy::GetCenterPosition() const
{
	return sprite_->GetPosition();
}

std::string Enemy::GetColliderName() const
{
	return "enemy";
}

float Enemy::GetRadius() const
{
	return 32.0f;
}

void Enemy::Init(const Vector2& position)
{
	sprite_ = std::make_unique<Sprite>();
	sprite_->Initialize("uvChecker.png");
	sprite_->SetAnchorPoint({ 0.5f,0.5f });
	sprite_->SetSize({ 64.0f,64.0f });
	sprite_->SetPosition(position);

	ChangeState(std::make_unique<EnemyMoveState>(this));
}

void Enemy::Update()
{
	state_->Update();

	if (!isActive_) {
		return;
	}

	sprite_->Update();

}

void Enemy::Draw()
{
	state_->Draw();

	if (!isActive_) {
		return;
	}

	sprite_->Draw();

}

void Enemy::ChangeState(std::unique_ptr<EnemyBaseState> newState)
{
	state_ = std::move(newState);
	state_->Initialize();
}
