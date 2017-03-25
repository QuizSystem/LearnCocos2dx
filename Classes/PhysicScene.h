#ifndef __PHYSIC_SCENE_H__
#define __PHYSIC_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class Physic : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(Physic);
private:
    cocos2d::PhysicsWorld *world;
    void setPhysicWorld(cocos2d::PhysicsWorld *m_world) {
        world = m_world;
    }
};

#endif // __PHYSIC_SCENE_H__
