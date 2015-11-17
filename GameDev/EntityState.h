#pragma once
enum EntityState
{
	None = 0,
	IdleLeft,
	WalkLeftStart,
	WalkLeft,
	CrouchLeft,
	ShootLeft,
	JumpLeft,
	JumpLeftMove,

	// Keep all left movment above this
	EndLeftMovement,

	// Start right movement below here
	IdleRight,
	WalkRightStart,
	WalkRight,
	CrouchRight,
	ShootRight,
	JumpRight,
	JumpRightMove,

	// Keep last
	EndRightMovement
};