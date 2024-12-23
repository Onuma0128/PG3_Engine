#include "EnemyDeadState.h"

#include "gameScene/enemy/Enemy.h"
#include "gameScene/enemy/state/EnemyMoveState.h"

EnemyDeadState::EnemyDeadState(Enemy* enemy) :EnemyBaseState(enemy) {}

void EnemyDeadState::Initialize()
{
	deadFrame_ = 0.0f;
}

void EnemyDeadState::Finalize()
{
}

void EnemyDeadState::Update()
{
	deadFrame_ += 1.0f / 60.0f;

	if (deadFrame_ >= 1.0f) {
		enemy_->SetIsActive(true);
		enemy_->ChangeState(std::make_unique<EnemyMoveState>(enemy_));
	}
}

void EnemyDeadState::Draw()
{
}
