#include "SpriteBase.h"

SpriteBase* SpriteBase::instance_ = nullptr;

SpriteBase* SpriteBase::GetInstance()
{
	if (instance_ == nullptr) {
		instance_ = new SpriteBase;
	}
	return instance_;
}

void SpriteBase::Initialize(DirectXEngine* dxEngine)
{
	dxEngine_ = dxEngine;

	rootSignature_ = dxEngine_->GetPipelineState()->CreateSpriteRootSignature().Get();
	pipelineState_ = dxEngine_->GetPipelineState()->CreateSpritePipelineState().Get();
}

void SpriteBase::DrawBase()
{
	dxEngine_->GetCommandList()->SetGraphicsRootSignature(rootSignature_.Get());
	dxEngine_->GetCommandList()->SetPipelineState(pipelineState_.Get());
	dxEngine_->GetCommandList()->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

void SpriteBase::Finalize()
{
	delete instance_;
	instance_ = nullptr;
}
