#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class SceneManager
{
private:
    std::string scene;

public:
    void changeScene(const std::string sceneName);
    std::string getCurrentScene();

    SceneManager();
    ~SceneManager();
};