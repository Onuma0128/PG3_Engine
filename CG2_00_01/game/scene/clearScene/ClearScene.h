#pragma once
#include <memory>

#include "BaseScene.h"

#include "Camera.h"
#include "Sprite.h"

class ClearScene : public BaseScene
{
public:

	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;

private:

	std::unique_ptr<Camera> camera_ = nullptr;

	std::unique_ptr<Sprite> sprite_ = nullptr;

};

