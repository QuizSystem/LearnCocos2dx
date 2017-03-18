#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    CCLOG("width = %f, height = %f", visibleSize.width, visibleSize.height);
    CCLOG("x = %f, y = %f", origin.x, origin.y);
    
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    sprite->setAnchorPoint(Vec2::ZERO);
    //    sprite->setRotation(-45);
    //    sprite->setSkewX(-20);
    //    sprite->setSkewY(-20);
    this->addChild(sprite, 0);
    
    auto square = Sprite::create("square.png");
    square->setAnchorPoint(Vec2::ZERO);
    square->setPosition(Vec2(origin.x , origin.y));
    square->setScale(0.5, 0.5);
    square->setRotation(360-45);
//    square->setSkewX(20);
//    square->setSkewY(20);
    this->addChild(square);
    
    // Action
    float secondTime = 5;
    auto actionMoveTo1 = MoveTo::create(secondTime, Vec2(300, 100)); // xnew = 300, ynew = 100
    auto actionMoveTo2 = MoveTo::create(secondTime, Vec2(300, 100));
    auto actionMoveBy = MoveBy::create(secondTime, Vec2(300, 100)); // xnew = x + 300, ynew = y + 100
    
//    sprite->runAction(actionMoveTo1);
//    sprite->runAction(actionMoveBy);
//    square->runAction(actionMoveTo2);
    
    // Rotate
    auto actionRotateTo = RotateTo::create(secondTime, 45); // rotate to -- xoay den 45 do
    auto actionRotateBy = RotateBy::create(secondTime, 45); // rotate continue -- xoay cong them 45 do
//    square->runAction(actionRotateTo);
//    square->runAction(actionMoveTo1);
    
    auto actionSequence = Sequence::create(actionMoveTo1, actionRotateBy, NULL);
    square->runAction(actionSequence);
    
//    std::vector<int> array;
//    array = {13, 7, 1992, 1, 8, 1994};
//    CCLOG("Array.size = %lu", array.size());
//    sayHello();
//    CCLOG("Sum = %i", sum(1, 2));
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);
    
    return true;
}

void HelloWorld::sayHello() {
    CCLOG("Thieu Mao");
}

int HelloWorld::sum(int number1, int number2) {
    return number1 + number2;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
    #endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
