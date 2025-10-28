#include "TestScene.h"
#include "Engine\\SceneManager.h"
#include "Engine\\Fbx.h"
#include "Engine\\Model.h"
#include "Engine\\Input.h" // キー入力取得用

TestScene::TestScene(GameObject* parent)
    : GameObject(parent, "TestScene")
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()
{
    // モデルの読み込み（oden.fbxはプロジェクトのリソースに配置）
    hModel_ = Model::Load("Suika.fbx");
    assert(hModel_ >= 0);
    transform_.scale_.x = 0.7f;
    transform_.scale_.y = 0.7f;
    transform_.scale_.z = 0.7f;
}

void TestScene::Update()
{
    transform_.rotate_.y += 1.0f;
    // スペースキーでPlaySceneへ遷移
    if (GetAsyncKeyState(VK_SPACE)) {
        // 親がSceneManagerであることを前提にキャスト
        auto sceneManager = static_cast<SceneManager*>(pParent_);
        sceneManager->ChangeScene(SCENE_ID_PLAY);
    }
}

void TestScene::Draw()
{
    if (hModel_ >= 0) {
        Model::SetTransform(hModel_, transform_);
        Model::Draw(hModel_);
    }
}

void TestScene::Release()
{
    // 必要に応じてモデルのリリース処理
    hModel_ = -1;
}