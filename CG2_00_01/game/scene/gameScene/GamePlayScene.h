#pragma once
#include <memory>
#include <vector>

#include "BaseScene.h"

#include "Object3d.h"
#include "WorldTransform.h"
#include "Camera.h"

#include "player/Player.h"
#include "enemy/Enemy.h"
#include "collider/Collider.h"
#include "collider/CollisionManager.h"

class GamePlayScene : public BaseScene
{
public:

	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;


	void CheckAllCollisions();

private:

	std::unique_ptr<Camera> camera_ = nullptr;

	std::unique_ptr<Object3d> model_ = nullptr;
	std::unique_ptr<WorldTransform> transform_ = nullptr;

	std::unique_ptr<Object3d> teapot_ = nullptr;
	std::unique_ptr<WorldTransform> teapotTrans_ = nullptr;


	std::unique_ptr<Player> player_ = nullptr;
	std::vector<std::unique_ptr<Enemy>> enemys_;

	std::unique_ptr<CollisionManager> collisionManager_;

};

