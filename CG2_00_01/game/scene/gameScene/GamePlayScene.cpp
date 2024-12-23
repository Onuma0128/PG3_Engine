#include "GamePlayScene.h"

#include "CameraManager.h"
#include "SceneManager.h"
#include "ModelManager.h"
#include "Input.h"

#include "Object3dBase.h"
#include "SpriteBase.h"
#include "PrimitiveDrawer.h"

#include "titleScene/TitleScene.h"

void GamePlayScene::Initialize()
{
	// Cameraの初期化
	// ===============
	// Cameraのポインタを初期化
	// CameraManagerに登録
	// ===============
	camera_ = std::make_unique<Camera>();
	camera_->Initialize();
	CameraManager::GetInstance()->SetCamera(camera_.get());

	transform_ = std::make_unique<WorldTransform>();

	ModelManager::GetInstance()->LoadModel("resources", "terrain.obj");
	model_ = std::make_unique<Object3d>();
	model_->Initialize("terrain.obj", transform_.get());

	teapotTrans_ = std::make_unique<WorldTransform>();

	ModelManager::GetInstance()->LoadModel("resources", "teapot.obj");
	teapot_ = std::make_unique<Object3d>();
	teapot_->Initialize("teapot.obj", teapotTrans_.get());
	teapotTrans_->parent_ = transform_.get();

	player_ = std::make_unique<Player>();
	player_->Init();

	for (int i = 0; i < 3; ++i) {
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>();
		enemy->Init({ 320.0f + i * 320.0f,64.0f });
		enemys_.push_back(std::move(enemy));
	}

	collisionManager_ = std::make_unique<CollisionManager>();
}

void GamePlayScene::Finalize()
{
}

void GamePlayScene::Update()
{
	transform_->rotation_.y += 0.01f;

	teapot_->Update();
	model_->Update();

	player_->Update();

	for (auto& enemy : enemys_) {
		enemy->Update();
	}

	CheckAllCollisions();

	// ゲームクリアで状態遷移
	//SceneManager::GetInstance()->ChangeScene("Clear");
}

void GamePlayScene::Draw()
{
	// Modelの描画準備
	Object3dBase::GetInstance()->DrawBase();
	
	model_->Draw();
	teapot_->Draw();

	// Spriteの描画準備
	SpriteBase::GetInstance()->DrawBase();
	
	player_->Draw();

	for (auto& enemy : enemys_) {
		enemy->Draw();
	}

	// Lineの描画準備
	PrimitiveDrawer::GetInstance()->DrawBase();




	// Particleの描画

}

void GamePlayScene::CheckAllCollisions()
{
	collisionManager_->Reset();

	for (auto& bullet : player_->GetBullets()) {
		if (bullet->GetIsActive()) {
			collisionManager_->AddCollider(bullet.get());
		}
	}
	for (auto& enemy : enemys_) {
		if (enemy->GetIsActive()) {
			collisionManager_->AddCollider(enemy.get());
		}
	}

	collisionManager_->CheckAllCollisions();
}
