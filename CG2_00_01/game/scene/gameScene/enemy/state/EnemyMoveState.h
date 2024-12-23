#pragma once

#include "gameScene/enemy/state/EnemyBaseState.h"

class EnemyMoveState : public EnemyBaseState
{
public:

	EnemyMoveState(Enemy* enemy);

	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;

private:



};

