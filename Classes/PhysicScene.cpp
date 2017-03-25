#include "PhysicScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

USING_NS_CC;


Scene *Physic::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = Physic::create();
    //layer->setPhysicWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

bool Physic::init() {
    if ( !Layer::init() ) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 2);
    auto edgeNode = Node::create();
    edgeNode->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);
    
    // add sprite square
    auto square = Sprite::create("square.png");
    square->setAnchorPoint(Vec2::ZERO);
    square->setPosition(visibleSize.width*0.4, visibleSize.height/2);
    square->setScale(0.3, 0.3);
    auto bodySquare = PhysicsBody::createBox(square->getContentSize());
    bodySquare->setCollisionBitmask(1);
    bodySquare->setContactTestBitmask(true);
    bodySquare->setGravityEnable(false);
    bodySquare->setDynamic(false);
    square->setPhysicsBody(bodySquare);
    this->addChild(square);
    
    // add sprite hello
    auto hello = Sprite::create("square.png");
    hello->setAnchorPoint(Vec2::ZERO);
    hello->setPosition(visibleSize.width*0.4, visibleSize.height*0.8);
    hello->setScale(0.3, 0.3);
    auto bodyHello = PhysicsBody::createBox(hello->getContentSize());
    bodyHello->setCollisionBitmask(2);
    bodyHello->setContactTestBitmask(true);
//    bodyHello->setGravityEnable(false);
    hello->setPhysicsBody(bodyHello);
    this->addChild(hello);
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Physic::OnPhysicContact, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    return true;
}

bool Physic::OnPhysicContact(cocos2d::PhysicsContact &contact) {
    auto shapeA = contact.getShapeA()->getBody();
    auto shapeB = contact.getShapeB()->getBody();
    
    if ((shapeA->getCollisionBitmask()==1 && shapeB->getCollisionBitmask()==2)
        || (shapeA->getCollisionBitmask()==2 && shapeB->getCollisionBitmask()==1)) {
        CCLOG("Have a collision");
    }
    return true;
}
