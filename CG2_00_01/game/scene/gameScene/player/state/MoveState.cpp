#include "MoveState.h"

#include "Input.h"

#include "gameScene/player/Player.h"
#include "gameScene/player/state/AttackState.h"

MoveState::MoveState(Player* player) : BaseState(player) {}

void MoveState::Initialize()
{
}

void MoveState::Finalize()
{
}

void MoveState::Update()
{
	Vector2 position = player_->GetSprite()->GetPosition();
	const float kSpeed = 5.0f;

	if (Input::GetInstance()->PushKey(DIK_W)) {
		position.y -= kSpeed;
	}
	if (Input::GetInstance()->PushKey(DIK_S)) {
		position.y += kSpeed;
	}
	if (Input::GetInstance()->PushKey(DIK_A)) {
		position.x -= kSpeed;
	}
	if (Input::GetInstance()->PushKey(DIK_D)) {
		position.x += kSpeed;
	}

	player_->GetSprite()->SetPosition(position);

	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		player_->ChangeState(std::make_unique<AttackState>(player_));
	}
}

void MoveState::Draw()
{
}
