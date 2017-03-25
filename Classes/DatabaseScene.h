#ifndef __DATABASE_SCENE_H__
#define __DATABASE_SCENE_H__

#include "cocos2d.h"
#include "wxsqlite/sqlite3.h"

using namespace cocos2d;

class Database : public cocos2d::Layer {
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Database);
};

#endif
