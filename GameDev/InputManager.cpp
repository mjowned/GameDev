#include "InputManager.h"

InputManager::InputManager()
{
	input = new std::unordered_map<SDL_Keycode, bool>();
}

InputManager::~InputManager()
{
	delete input;
}

void InputManager::SetKeyInput(SDL_Keycode key)
{
	if (input->find(key) == input->end())
	{
		input->insert({ key, true });
	}
	else
	{
		input->at(key) = true;
	}
}

void InputManager::ResetKeyInput(SDL_Keycode key)
{
	if (!(input->find(key) == input->end()))
	{
		input->at(key) = false;
	}
}

void InputManager::SetMouseInput(SDL_Event _event)
{
	mouseEvent = _event;
}

void InputManager::ResetMouseInput()
{
	mouseEvent = SDL_Event();
}


SDL_Event InputManager::GetMouseInput()
{
	return mouseEvent;
}

std::unordered_map<SDL_Keycode, bool>* InputManager::GetKeyInput()
{
	return input;
}