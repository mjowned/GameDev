#pragma once
#include "Npc.h"
#include "Player.h"
#include <iostream>
#include <unordered_map>
#include "BehaviourFactory.h"
#include "Ground.h"
#include "Bullet.h"


class EntityFactory
{
public:
	EntityFactory(b2World& world, std::vector<Actor*>* _actor,BehaviourFactory* _bf, DrawableContainer* _drawContainer);
	~EntityFactory();
	Entity* CreateEntity(float x, float y, float height, float width, EntityType type);
	Actor* CreateActor(int _hitdmg, int _healt, float x, float y, float height, float width, EntityType type);
	Bullet* CreateBullet(float x, float y, int width, int height, int dmg, b2Vec2 direction, EntityType type);
	b2Body* CreateBody(float x, float y, float height, float width, EntityType type);

	b2Body* CreateBody(float x, float y, float height, float width, float den, EntityType type);

private:
	DrawableContainer* drawContainer;
	BehaviourFactory* bf;
	std::unordered_map<EntityType,Entity*> entityRegistery;
	std::unordered_map<EntityType, Actor*> actorRegistery;
	std::unordered_map<EntityType, b2BodyDef > bodyRegistery;
	std::unordered_map<EntityType, Bullet* > bulletRegistery;
	b2World& world;
	std::vector<Actor*>* actor;

};

