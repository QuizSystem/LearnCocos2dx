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
    
//    // UIButton
////    auto button = ui::Button::create("square.png");
////    button->setPosition(visibleSize / 2);
////    button->addTouchEventListener([&](Ref *sender, ui::Widget::TouchEventType type) {
////        switch (type) {
////            case ui::Widget::TouchEventType::BEGAN:
////                CCLOG("Button BEGAN");
////                break;
////            case ui::Widget::TouchEventType::MOVED:
////                CCLOG("Button MOVED");
////                break;
////            case ui::Widget::TouchEventType::ENDED:
////                CCLOG("Button ENDED");
////                break;
////            case ui::Widget::TouchEventType::CANCELED:
////                CCLOG("Button CANCELED");
////                break;
////            default:
////                break;
////        }
////    });
////    this->addChild(button);
//    
//    auto sprite = Sprite::create("HelloWorld.png");
//    sprite->setPosition(visibleSize / 2);
//    sprite->setScale(2);
//    this->addChild(sprite);
//    
////    //UI Checkbox
////    auto checkbox = ui::CheckBox::create("uncheck.png", "check.png");
////    checkbox->setPosition(visibleSize / 2);
////    checkbox->addEventListener([&](Ref *sender, ui::CheckBox::EventType type){
////        switch (type) {
////            case ui::CheckBox::EventType::SELECTED:
////                CCLOG("Seleted");
////                break;
////            case ui::CheckBox::EventType::UNSELECTED:
////                CCLOG("Unseleted");
////                break;
////            default:
////                break;
////        }
////    });
////    this->addChild(checkbox);
//    
//    // UI Load Action
//    auto loadingBar = ui::LoadingBar::create("blueline.png");
//    loadingBar->setScaleX(0.3);
//    loadingBar->setPosition(visibleSize / 2);
//    loadingBar->setDirection(ui::LoadingBar::Direction::LEFT);
//    loadingBar->setPercent(0);
//    this->addChild(loadingBar);
//    this->schedule([=](float delta) {
//        float percent = loadingBar->getPercent();
//        percent++;
//        loadingBar->setPercent(percent);
//        if (percent >= 100) {
//            this->unschedule("updateLoadingBar");
//        }
//    }, 0.1f, "updateLoadingBar");
//    
////    square = Sprite::create("square.png");
////    square->setPosition(Vec2::ZERO);
////    this->addChild(square);
////    
////    // Touch
////    auto touchListener = EventListenerTouchOneByOne::create();
////    touchListener->onTouchBegan = CC_CALLBACK_2(Splash::onTouchBegan, this);
////    touchListener->onTouchMoved = CC_CALLBACK_2(Splash::onTouchMoved, this);
////    touchListener->onTouchEnded = CC_CALLBACK_2(Splash::onTouchEnded, this);
////    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
//    
//    auto closeItem = MenuItemImage::create(
//                                           "CloseNormal.png",
//                                           "CloseSelected.png",
//                                           CC_CALLBACK_1(Splash::menuCloseCallback, this));
//    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                origin.y + closeItem->getContentSize().height/2));
//    auto menu = Menu::create(closeItem, NULL);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
    
//    // UI Menu
//    auto menuImages = MenuItemImage::create("uncheck.png", "check.png", CC_CALLBACK_1(Splash::onClickMenuItem, this));
//    menuImages->setTag(1);
//    auto menuImages1 = MenuItemImage::create("redline.png", "blueline.png", CC_CALLBACK_1(Splash::onClickMenuItem, this));
//    menuImages1->setTag(2);
//    
//    auto menu = Menu::create(menuImages, menuImages1, NULL);
//    menu->setPosition(visibleSize / 2);
//    menu->alignItemsVertically();
//    this->addChild(menu);
    
//    // PageView
//    auto pageView = ui::PageView::create();
//    pageView->setPosition(Vec2::ZERO);
//    pageView->setContentSize(visibleSize);
//    this->addChild(pageView);
//    for (int i = 0; i < 3; i++) {
//        auto page = ui::Layout::create();
//        page->setContentSize(pageView->getContentSize());
//        auto mySprite = cocos2d::Sprite::create("square.png");
//        mySprite->setScale(2);
//        mySprite->setPosition(visibleSize / 2);
//        page->addChild(mySprite);
//        pageView->insertPage(page, i);
//    }
//    pageView->addEventListener([](Ref *sender, ui::PageView::EventType type){
//        if (type == ui::PageView::EventType::TURNING) {
//            auto pageView = dynamic_cast<ui::PageView *>(sender);
//            CCLOG("Current page = %zd", pageView->getCurrentPageIndex());
//        }
//    });

    // ScrollView
    auto scrollView = ui::ScrollView::create();
    scrollView->setPosition(Vec2::ZERO);
    scrollView->setDirection(ui::ScrollView::Direction::BOTH);
    scrollView->setBounceEnabled(true);
    this->addChild(scrollView);
    auto mySprite = cocos2d::Sprite::create("HelloWorld.png");
    mySprite->setScale(2);
    mySprite->setPosition(mySprite->getBoundingBox().size / 2);
    scrollView->addChild(mySprite);
    scrollView->setInnerContainerSize(mySprite->getBoundingBox().size);
    scrollView->setContentSize(mySprite->getContentSize());
    
    return true;
}

void Splash::onClickMenuItem(cocos2d::Ref *sender) {
    auto node = dynamic_cast<Node *>(sender);
    CCLOG("tag = %d", node->getTag());
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
