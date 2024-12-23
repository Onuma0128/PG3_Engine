#include "EnemyMoveState.h"

#include "gameScene/enemy/Enemy.h"
#include "gameScene/enemy/state/EnemyDeadState.h"

EnemyMoveState::EnemyMoveState(Enemy* enemy) :EnemyBaseState(enemy){}

void EnemyMoveState::Initialize()
{
}

void EnemyMoveState::Finalize()
{
}

void EnemyMoveState::Update()
{
	if (!enemy_->GetIsActive()) {
		enemy_->ChangeState(std::make_unique<EnemyDeadState>(enemy_));
	}
}

void EnemyMoveState::Draw()
{
}
