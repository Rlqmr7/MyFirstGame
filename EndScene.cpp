#include "EndScene.h"
#include "Engine\\SceneManager.h"
#include "Engine\\Fbx.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h" // キー入力取得用

EndScene::EndScene(GameObject* parent)
    : GameObject(parent, "EndScene")
{
}

EndScene::~EndScene()
{
}

void EndScene::Initialize()
{
    // モデルの読み込み（oden.fbxはプロジェクトのリソースに配置）
    hModel_ = Model::Load("Oden.fbx");
    assert(hModel_ >= 0);
    transform_.scale_.x = 0.4;
    transform_.scale_.y = 0.4;
    transform_.scale_.z = 0.4;
}

void EndScene::Update()
{
}

void EndScene::Draw()
{
    if (hModel_ >= 0) {
        Model::SetTransform(hModel_, transform_);
        Model::Draw(hModel_);
    }
}

void EndScene::Release()
{
    // 必要に応じてモデルのリリース処理
    hModel_ = -1;
}