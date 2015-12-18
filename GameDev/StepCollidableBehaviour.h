#pragma once
#include "Actor.h"
#include "CollidableBehaviour.h"
class StepCollidableBehaviour :
	public CollidableBehaviour
{
public:
	StepCollidableBehaviour();
	~StepCollidableBehaviour();
	void Hit(CollidableBehaviour* cb);
	void Unhit(CollidableBehaviour* cb);
	virtual CollidableBehaviour* EmptyClone();

	void SetLeft(bool l);

private:
	int steps;
	bool left;
};

