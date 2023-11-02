#pragma once
#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "WinApp.h"
enum class Scene {
	Title,
	Select,
	Game,
};
class PlayScene {
private:
	Scene scene = Scene::Title;

};
