#pragma once

#include "Vector2.h"

#include "gameScene/player/state/BaseState.h"

class MoveState : public BaseState
{
public:

	MoveState(Player* player);

	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;

private:


};