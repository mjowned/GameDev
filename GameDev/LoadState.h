#pragma once
#include "IGameState.h"
#include "GameStateManager.h"
#include "SoundBank.h"
#include <thread>

class LoadState : public IGameState {
private:
	GameStateManager* gsm;
	DrawableContainer* drawableContainer;
	static IGameState* playState;
	static bool loadedPlay;
	static void LoadPlayState(GameStateManager* gsm);

public:
	LoadState() { };
	virtual ~LoadState();

	void Init(GameStateManager* gsm);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleMouseEvents(SDL_Event mainEvent);
	void HandleKeyEvents(std::unordered_map<SDL_Keycode, bool>* _events);
	void Update(float dt);
	void Draw();
};