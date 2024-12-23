#pragma once

#include "gameScene/enemy/state/EnemyBaseState.h"

class EnemyDeadState : public EnemyBaseState
{
public:

	EnemyDeadState(Enemy* enemy);

	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;

private:

	float deadFrame_ = 0.0f;

};