#pragma once
#include "Apc.h"
#include "Vehicle.h"
#include <iostream>
#include <unordered_map>
#include "BehaviourFactory.h"
#include "Ground.h"
#include "Bullet.h"
#include "BareEntity.h"
#include "Cannon.h"
#include "Shotgun.h"
#include "Acorn.h"
#include "NpcStatsContainer.h" //indirectly included EntityStatsContainer
#include "CollisionType.h"
#include "DeleteQueryCallback.h"
#include "CollidableContainer.h"
#include "MoveableContainer.h"

class EntityFactory
{
public:
	EntityFactory(b2World& world, std::vector<Actor*>* _actor,std::vector<Entity*>*_ent,BehaviourFactory* _bf, Level* _level, DrawableContainer* _drawContainer, MoveableContainer* _moveContainer);
	~EntityFactory();
	Entity* CreateEntity(float x, float y, float height, float width, EntityType type);
	Entity* CreateEntity(float x, float y, EntityType type);
	Actor* CreateActor(int _hitdmg, int _healt, float x, float y, float height, float width, EntityType type);
	Actor* CreateActor(float x, float y, EntityType type);
	Player* CreatePlayer(int _hitdmg, int _healt, float x, float y, float height, float width, Player* _player);
	Bullet* CreateBullet(float x, float y, int width, int height, int dmg, b2Vec2 direction, uint16 categoryBits, EntityType type);
	//b2Body* CreateActorBodyRound(float x, float y, float height, float width, float den, EntityType type);
	b2Body* CreateBody(float x, float y, float height, float width, EntityType type);
	Weapon* CreateWeapon(float x, float y, EntityType type);
	b2Body* CreateActorBody(float x, float y, float height, float width, float den, EntityType type);
	b2Body* CreateActorRoundBody(float x, float y, float height, float width, float den, EntityType type, Actor* ent);
	b2Body* CreateBody(float x, float y, float height, float width, float den, EntityType type);

	int GetBossCount();
	void DecrementBossCount();

	void ClickAndDeleteEntity(float x, float y, DrawableContainer* drawableContainer, MoveableContainer* moveableContainer, CollidableContainer* collidableContainer);
private:
	void DeleteEntity(Entity* entity, DrawableContainer* drawableContainer, MoveableContainer* moveableContainer, CollidableContainer* collidableContainer);

public:
	//Level Editor functions
	std::vector<EntityType>* GetActorTypeList();
	std::vector<EntityType>* GetEntityTypeList();

private:
	DrawableContainer* drawContainer;
	MoveableContainer* moveContainer;
	BehaviourFactory* bf;

	std::unordered_map<EntityType, Weapon*> weaponRegistery;
	std::unordered_map<EntityType, Entity*> entityRegistery;
	std::unordered_map<EntityType, Actor*> actorRegistery;
	std::unordered_map<EntityType, b2BodyDef > bodyRegistery;
	std::unordered_map<EntityType, Bullet* > bulletRegistery;

	std::unordered_map<EntityType, Actor*> editorActorRegistery;
	std::unordered_map<EntityType, NpcStatsContainer*> npcStatsRegistery;
	std::unordered_map<EntityType, EntityStatsContainer*> entityStatsRegistery;
	std::unordered_map<EntityType, float> restitutionRegistery;
	std::unordered_map<EntityType, CollisionType> entityCollisionRegistery;

	b2World& world;
	std::vector<Actor*>* actor;
	std::vector<Entity*>* entities;

	DeleteQueryCallback* deleteQueryCallback;
	Level* level;
	int bossCount;
};

