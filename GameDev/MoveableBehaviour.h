#pragma once
#include "Behaviour.h"

class MoveableBehaviour :
	public Behaviour
{
public:
	MoveableBehaviour();
	virtual ~MoveableBehaviour();

	MoveableBehaviour* EmptyClone();

	virtual void Move();
};


















