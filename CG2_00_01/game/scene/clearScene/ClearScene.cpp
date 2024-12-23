#include "ClearScene.h"

#include "CameraManager.h"
#include "SceneManager.h"
#include "ModelManager.h"
#include "Input.h"

#include "Object3dBase.h"
#include "SpriteBase.h"
#include "PrimitiveDrawer.h"

void ClearScene::Initialize()
{
	// Cameraの初期化
	// ===============
	// Cameraのポインタを初期化
	// CameraManagerに登録
	// ===============
	camera_ = std::make_unique<Camera>();
	camera_->Initialize();
	CameraManager::GetInstance()->SetCamera(camera_.get());


	sprite_ = std::make_unique<Sprite>();
	sprite_->Initialize("Clear.png");
}

void ClearScene::Finalize()
{
}

void ClearScene::Update()
{
 	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		SceneManager::GetInstance()->ChangeScene("Title");
	}

	sprite_->Update();
}

void ClearScene::Draw()
{
	// Modelの描画準備
	Object3dBase::GetInstance()->DrawBase();




	// Spriteの描画準備
	SpriteBase::GetInstance()->DrawBase();

	sprite_->Draw();


	// Lineの描画準備
	PrimitiveDrawer::GetInstance()->DrawBase();




	// Particleの描画

}
