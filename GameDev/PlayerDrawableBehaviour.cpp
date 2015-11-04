#include "PlayerDrawableBehaviour.h"


PlayerDrawableBehaviour::PlayerDrawableBehaviour(SDL_Renderer* renderer, int screenwidth, int screenheight) : DrawableBehaviour(renderer, screenwidth, screenheight)
{
	LoadMedia();
}


PlayerDrawableBehaviour::~PlayerDrawableBehaviour()
{
}

void PlayerDrawableBehaviour::Draw()
{
	// Render current frame SCREEN SIZE NOT YET SET!!!
	SDL_Rect* currentClip = &sprites[currentFrame / sprites.size()];
	spriteSheetTexture->render(renderer, (screenWidth - currentClip->w) / 2, (screenHeight - currentClip->h) / 2, currentClip);

	//Go to next frame 
	++currentFrame;

	//Cycle animation 
	if (currentFrame / sprites.size() >= sprites.size())
	{
		currentFrame = 0;
	}
}

void PlayerDrawableBehaviour::SetSprites(vector<SDL_Rect> sdl_sprites)
{
	sprites = sdl_sprites;
}

bool PlayerDrawableBehaviour::LoadMedia()
{
	//Loading success flag
	bool success = true;

	spritesheetPath = "";
	spritesheetName = "sprites.png";

	//Load sprite sheet texture
	if (!spriteSheetTexture->loadFromFile(renderer, spritesheetPath + spritesheetName))
	{
		printf("Failed to load spritesheet! \n");
		success = false;
	}
	else
	{
		idleSprites.resize(IDLE_ANIMATION_FRAMES);

		idleSprites[0].x = 4;
		idleSprites[0].y = 0;
		idleSprites[0].w = 30; //entity->GetWidth();
		idleSprites[0].h = 40; //entity->GetHeight();

		idleSprites[1].x = idleSprites[0].x + idleSprites[0].w;
		idleSprites[1].y = 0;
		idleSprites[1].w = 30; //entity->GetWidth();
		idleSprites[1].h = 40; //entity->GetHeight();

		idleSprites[2].x = idleSprites[1].x + idleSprites[1].w;
		idleSprites[2].y = 0;
		idleSprites[2].w = 30; //entity->GetWidth();
		idleSprites[2].h = 40; //entity->GetHeight();

		walkSprites.resize(WALK_ANIMATION_FRAMES);

		walkSprites[0].x = 107;
		walkSprites[0].y = 0;
		walkSprites[0].w = 30; //entity->GetWidth();
		walkSprites[0].h = 40; //entity->GetHeight();

		walkSprites[1].x = walkSprites[0].x + walkSprites[0].w;
		walkSprites[1].y = 0;
		walkSprites[1].w = 30; //entity->GetWidth();
		walkSprites[1].h = 40; //entity->GetHeight();

		walkSprites[2].x = walkSprites[1].x + walkSprites[1].w;
		walkSprites[2].y = 0;
		walkSprites[2].w = 30; //entity->GetWidth();
		walkSprites[2].h = 40; //entity->GetHeight();

		walkSprites[3].x = walkSprites[2].x + walkSprites[2].w;
		walkSprites[3].y = 0;
		walkSprites[3].w = 30; //entity->GetWidth();
		walkSprites[3].h = 40; //entity->GetHeight();

		walkSprites[4].x = walkSprites[3].x + walkSprites[3].w;
		walkSprites[4].y = 0;
		walkSprites[4].w = 30; //entity->GetWidth();
		walkSprites[4].h = 40; //entity->GetHeight();

		walkSprites[5].x = walkSprites[4].x + walkSprites[4].w;
		walkSprites[5].y = 0;
		walkSprites[5].w = 30; //entity->GetWidth();
		walkSprites[5].h = 40; //entity->GetHeight();

		walkSprites[6].x = walkSprites[5].x + walkSprites[5].w;
		walkSprites[6].y = 0;
		walkSprites[6].w = 30; //entity->GetWidth();
		walkSprites[6].h = 40; //entity->GetHeight();

		walkSprites[7].x = walkSprites[6].x + walkSprites[6].w;
		walkSprites[7].y = 0;
		walkSprites[7].w = 30; //entity->GetWidth();
		walkSprites[7].h = 40; //entity->GetHeight();

		walkSprites[8].x = walkSprites[7].x + walkSprites[7].w;
		walkSprites[8].y = 0;
		walkSprites[8].w = 30; //entity->GetWidth();
		walkSprites[8].h = 40; //entity->GetHeight();

		sprites = idleSprites;
	}

	return success;
}

PlayerDrawableBehaviour* PlayerDrawableBehaviour::EmptyClone()
{
	return new PlayerDrawableBehaviour(renderer, screenWidth, screenHeight);
}