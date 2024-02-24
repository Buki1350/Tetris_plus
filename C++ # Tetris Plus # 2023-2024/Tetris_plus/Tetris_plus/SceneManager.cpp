#include "SceneManager.h"

void SceneManager::changeScene(const std::string sceneName)
{
    scene = sceneName;
}

std::string SceneManager::getCurrentScene()
{
    return scene;
}

SceneManager::SceneManager()
{
    changeScene("Menu");
}

SceneManager::~SceneManager()
{
}