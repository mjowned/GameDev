#include "Actor.h"

Actor::Actor()
{
	
	dead = false;
}


void Actor::InitActor(b2Body* _body, int _hitdmg, int _healt, float _width, float _height, EntityType _type, BehaviourFactory* bf, DrawableContainer* drawContainer){
	Init(_body, _width, _height, _type, bf, drawContainer);
	hitdmg = _hitdmg;
	healt = _healt;
	col = bf->CreateCollidableBehaviour(type);
	col->Init(this);
	body->SetUserData(col);

}
Actor* Actor::EmptyClone(){

	return new Actor();
}

Actor::~Actor()
{
}

void Actor::SetState(ActorState* new_state)
{
	state = new_state;
}

ActorState* Actor::GetState()
{
	return state;
}
void Actor::SetHealt(int _healt){
	if (_healt < 0){
		dead = true;
	}
	else{
		healt = healt;
	}
}
bool Actor::IsDead(){
	return dead;
}
int Actor::GetHealt(){
	return healt;
}
int Actor::GetDamage(){
	return hitdmg;
}
