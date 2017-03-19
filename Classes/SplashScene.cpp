#include "SplashScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Sprite *square;

Scene* Splash::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Splash::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Splash::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // UIButton
    auto button = ui::Button::create("square.png");
    button->setPosition(visibleSize / 2);
    button->addTouchEventListener([&](Ref *sender, ui::Widget::TouchEventType type) {
        switch (type) {
            case ui::Widget::TouchEventType::BEGAN:
                CCLOG("Button BEGAN");
                break;
            case ui::Widget::TouchEventType::MOVED:
                CCLOG("Button MOVED");
                break;
            case ui::Widget::TouchEventType::ENDED:
                CCLOG("Button ENDED");
                break;
            case ui::Widget::TouchEventType::CANCELED:
                CCLOG("Button CANCELED");
                break;
            default:
                break;
        }
    });
    this->addChild(button);
    
//    square = Sprite::create("square.png");
//    square->setPosition(Vec2::ZERO);
//    this->addChild(square);
//    
//    // Touch
//    auto touchListener = EventListenerTouchOneByOne::create();
//    touchListener->onTouchBegan = CC_CALLBACK_2(Splash::onTouchBegan, this);
//    touchListener->onTouchMoved = CC_CALLBACK_2(Splash::onTouchMoved, this);
//    touchListener->onTouchEnded = CC_CALLBACK_2(Splash::onTouchEnded, this);
//    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}

bool Splash::onTouchBegan(Touch *touch, Event *unused_event) {
    Vec2 touchLocation = touch->getLocation();
    auto actionMoveTo = MoveTo::create(0.5, touchLocation);
    square->runAction(actionMoveTo);
    return true;
}

void Splash::onTouchMoved(Touch *touch, Event *unused_event) {
    Vec2 touchLocation = touch->getLocation();
    square->setPosition(touchLocation);
}

void Splash::onTouchEnded(Touch *touch, Event *unused_event) {
    auto actionMoveTo = MoveTo::create(0.5, Vec2::ZERO);
    square->runAction(actionMoveTo);
//    auto helloWorldScene = HelloWorld::createScene(137);
//    Director::getInstance()->replaceScene(helloWorldScene);
}

void Splash::menuCloseCallback(Ref* pSender)
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
