#include "TitleScene.h"

#include "CameraManager.h"
#include "SceneManager.h"
#include "Input.h"

#include "Object3dBase.h"
#include "SpriteBase.h"
#include "PrimitiveDrawer.h"

#include "Quaternion.h"

#include "imgui.h"

void TitleScene::Initialize()
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
	sprite_->Initialize("Title.png");

}

void TitleScene::Finalize()
{
}

void TitleScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_RETURN)) {
		SceneManager::GetInstance()->ChangeScene("Game");
	}

	sprite_->Update();
}

void TitleScene::Draw()
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
