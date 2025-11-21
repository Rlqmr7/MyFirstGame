#include "Direct3D.h"
#include "SceneManager.h"
#include "..\\PlayScene.h"
#include "..\\TestScene.h"
#include "..\\EndScene.h"
#include "Model.h"

SceneManager::SceneManager(GameObject* parent)
	:GameObject(parent, "SceneManager")
{
}

SceneManager::~SceneManager()
{

}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TEST;
	currentcurrentSceneID_ = SCENE_ID_END;
	nextSceneID_ = currentSceneID_;
	Instantiate<TestScene>(this);
	//Instantiate<EndScene>(this);
}

void SceneManager::Update()
{
	if (currentSceneID_ != nextSceneID_)
	{
		//ƒV[ƒ“Ø‚è‘Ö‚¦ˆ—
		auto scene = childList_.front();
		scene->ReleaseSub();
		SAFE_DELETE(scene);
		childList_.clear();
		//Model::Release();

		switch (nextSceneID_)
		{
		case SCENE_ID_PLAY:
			Instantiate<PlayScene>(this);
			break;
		case SCENE_ID_TEST:
			Instantiate<TestScene>(this);
			break;
		case SCENE_ID_END:
			Instantiate<EndScene>(this);
			break;
		}
		currentSceneID_ = nextSceneID_;
	}
	
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SCENE_ID _nextScene)
{
	nextSceneID_ = _nextScene;
}
