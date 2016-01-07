#include "Weapon.h"
#include "EntityFactory.h"

Weapon::Weapon(){

	ammo = 100;
	maxAmmo = 200;
	fireSpeed = 250;
	vec = b2Vec2(0, 0);
	actor = nullptr;
	weaponDmg = 20;
}

void Weapon::SetWeaponDmg(int _weaponDmg){
	weaponDmg = _weaponDmg;
}
int Weapon::GetWeaponDmg(){
	return weaponDmg;
}
void Weapon::Init(float _xpos, float _ypos, float _angle, EntityState _state, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer, MoveableContainer* moveContainer){
	BareEntity::Init(_xpos, _ypos, _angle, _state, _type, bf, drawContainer, moveContainer);

}
void Weapon::Pickup(Actor* _actor, b2Vec2 _defaultShootingDirection)
{

	actor = _actor;
	
	
	defaultShootingDirection = _defaultShootingDirection;
}

Weapon* Weapon::EmptyClone(){
	return new Weapon;
}
Weapon::~Weapon()
{
}

void Weapon::AddAmmo(int _ammo){
	if (!((ammo + _ammo) > maxAmmo)){
		ammo = ammo + _ammo;
	}
	else{
		ammo = maxAmmo;
	}

}
void Weapon::SetXVec(float x){
	if (x < 0){
		if (angle != 2)
		{
			angle = angle + 2;
		}
	}
	else if (x > 0){
		angle = 0;
		
	}
	else{
		angle = 0;
	}
	
	vec.x = x;

}
void Weapon::SetYVec(float y){
	if (y > 0){
		angle = 1;
	}
	else if (y < 0){
		angle = 3;
	}
	else{
		angle = 0;
	}
	vec.y = y;
}
b2Vec2 Weapon::GetVec(){
	return vec;
}


float Weapon::GetXpos(){
	if (actor){
		return actor->GetXpos();
	}
	return xpos;
}
float Weapon::GetYpos(){
	if (actor){
		return actor->GetYpos();
	}
	return ypos;
}
float Weapon::GetAngle(){
	
	return angle;
}
bool Weapon::Shoot(EntityFactory* eF, float accumulatedDt, float manipulatorSpeed){
	if (accumulatedDt > (fireSpeed / manipulatorSpeed)) {
		if (ammo > 0){
			bool dir = false;
			if (vec.x == 0 && vec.y == 0){
				vec = defaultShootingDirection;
				dir = true;
			}
			eF->CreateBullet(actor->GetBody()->GetWorldCenter().x + vec.x / 200, actor->GetBody()->GetWorldCenter().y + vec.y / 200, 1, 1, weaponDmg, vec, 
				actor->GetBody()->GetFixtureList()->GetFilterData().categoryBits, EntityType::BULLET);

			SoundBank::GetInstance()->PlaySFX(SoundEffectType::GUNSHOT);
			ammo--;
			if (dir){
				vec.x = 0;
				vec.y = 0;
			}
			return true;
		}
	}
	return false;
}


void Weapon::SetFireSpeed(float speed){
	fireSpeed = speed;
}
float Weapon::GetFireSpeed(){
	return fireSpeed;
}

int Weapon::GetAmmo() {
	return ammo;
}