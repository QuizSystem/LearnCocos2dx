#include "DatabaseScene.h"
#include "wxsqlite/sqlite3.h"

USING_NS_CC;

Scene *Database::createScene() {
    auto scene = Scene::create();
    auto layer = Database::create();
    scene->addChild(layer);
    return scene;
}

bool Database::init() {
    if ( !Layer::init() ) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    sqlite3 *database;
    std::string path = FileUtils::getInstance()->getWritablePath() + "data.sql";
    if (sqlite3_open(path.c_str(), &database) != SQLITE_OK) {
        sqlite3_close(database);
        CCLOG("Error read database");
    } else {
        int result = sqlite3_exec(database, "create table student(ID integer primary key autoincrement, name text, sex text)", NULL, NULL, NULL);
        if (result != 0) {
            CCLOG("Failure create table");
        } else {
            CCLOG("Success create table");
        }
    }
    
    
    
    return true;
}
