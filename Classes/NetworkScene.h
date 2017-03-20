#ifndef __NETWORK_SCENE_H__
#define __NETWORK_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class Network : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Network);
};

#endif // __NETWORK_SCENE_H__
