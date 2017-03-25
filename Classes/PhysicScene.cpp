#include "PhysicScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

USING_NS_CC;


Scene *Physic::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = Physic::create();
    layer->setPhysicWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

bool Physic::init() {
    if ( !Layer::init() ) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // add sprite
//    auto square = Sprite::create("square.png");
//    square->setAnchorPoint(Vec2::ZERO);
//    square->setPosition(Vec2(origin.x , origin.y));
//    square->setScale(0.5, 0.5);
//    square->setSkewX(20);
//    square->setSkewY(20);
//    this->addChild(square);

    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 2);
    auto edgeNode = Node::create();
    edgeNode->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);
    
    return true;
}
