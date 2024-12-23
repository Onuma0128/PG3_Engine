#include "AttackState.h"

#include "Input.h"

#include "gameScene/player/Player.h"
#include "gameScene/player/state/MoveState.h" 

AttackState::AttackState(Player* player) : BaseState(player) {}

void AttackState::Initialize()
{
	player_->SetBullet();
}

void AttackState::Finalize()
{
}

void AttackState::Update()
{
	player_->ChangeState(std::make_unique<MoveState>(player_));
}

void AttackState::Draw()
{
}
