#pragma once
#include <d3d12.h>
#pragma comment(lib,"d3d12.lib")
#include <wrl.h>

#include <vector>

#include "Vector3.h"


using Microsoft::WRL::ComPtr;

class DirectXEngine;
class Camera;

class CameraManager
{
private:

	static CameraManager* instance_;

	CameraManager() = default;
	~CameraManager() = default;
	CameraManager(CameraManager&) = delete;
	CameraManager& operator=(CameraManager&) = delete;

	struct CameraForGPU {
		Vector3 worldPosition;
	};

public:

	// シングルトンインスタンスの取得
	static CameraManager* GetInstance();

	void Initialize(DirectXEngine* dxEngine);

	void Debug_ImGui();

	void Update();

	void Finalize();

	void SetCamera(Camera* camera) { 
		cameras_.push_back(camera); 
		activeCameraIndex_ = static_cast<uint32_t>(cameras_.size()) - 1;
		MakeCameraData();
	}
	void SetActiveCamera(uint32_t index) {
		activeCameraIndex_ = index;
		MakeCameraData();
	}

	Camera* GetActiveCamera()const { return cameras_[activeCameraIndex_]; }

	// カメラリソース
	ID3D12Resource* GetCameraResource()const { return cameraResource_.Get(); }

private:

	void MakeCameraData();

private:

	DirectXEngine* dxEngine_;

	// カメラを格納 <vector>
	std::vector<Camera*> cameras_;
	// 今どのカメラが動いているかIndex
	uint32_t activeCameraIndex_ = 0;

	/*==================== カメラデータ ====================*/

	ComPtr<ID3D12Resource> cameraResource_ = nullptr;
	CameraForGPU* cameraData_ = nullptr;

};

