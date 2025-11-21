#pragma once
#include "Engine\\GameObject.h"

class EndScene : public GameObject
{
public:
    EndScene(GameObject* parent);
    ~EndScene();
    void Initialize() override;
    void Update() override;
    void Draw() override;
    void Release() override;

private:
    int hModel_ = -1;
};