#pragma once

#include "Vector2.h"

#include "gameScene/player/state/BaseState.h"

class AttackState : public BaseState
{
public:

	AttackState(Player* player);

	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;

private:


};