#pragma once
#include <vector>
#include <SDL.h>
#include "LTexture.h"
#include "EntityState.h"

class Sprite
{
public:
	Sprite();
	~Sprite();

	SDL_Rect* GetAnimationFrame(EntityState state, int frame);
	void SetAnimationSet(EntityState state);
	int GetAnimationSize();
	void SetRenderer(SDL_Renderer* _renderer);
	LTexture* GetSpritesheet();
	bool LoadMedia(std::string path);

protected:
	virtual void SetAnimations();
	std::vector<SDL_Rect>* currentSprites;
	LTexture* spriteSheetTexture;
	SDL_Renderer* renderer;

	int IDLE_ANIMATION_FRAMES;
	int WALK_ANIMATION_FRAMES;
	int JUMP_ANIMATION_FRAMES;
	int SHOOT_ANIMATION_FRAMES;
	int CURRENT_ANIMATION_FRAMES;
	SDL_Rect defaultSprite;
	std::vector<SDL_Rect>* idleSprites;
	std::vector<SDL_Rect>* walkSprites;
};
