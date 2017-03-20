#include "NetworkScene.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "json/document.h"
#include "json/rapidjson.h"

USING_NS_CC;


Scene *Network::createScene()
{
    auto scene = Scene::create();
    auto layer = Network::create();
    scene->addChild(layer);
    return scene;
}

bool Network::init() {
    if ( !Layer::init() ) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    // add sprite
    auto square = Sprite::create("square.png");
    square->setAnchorPoint(Vec2::ZERO);
    square->setPosition(Vec2(origin.x , origin.y));
    square->setScale(0.5, 0.5);
    square->setSkewX(20);
    square->setSkewY(20);
    this->addChild(square);
    CCLOG("Network Screen");
//    // read json string
//    std::string myString = "{\"keytest\":\"Hello World\"}";
//    rapidjson::Document document;
//    document.Parse(myString.c_str());
//    if (document.HasParseError()) {
//        CCLOG("Error Parse");
//    } else {
//        if (document.IsObject() && document.HasMember("keytest")) {
//            CCLOG("keytest = %s", document["keytest"].GetString());
//        }
//    }
    // read json file
    std::string jsonstring = FileUtils::getInstance()->getStringFromFile("res/test.json");
    CCLOG("string file = %s", jsonstring.c_str());
    rapidjson::Document doc;
    doc.Parse(jsonstring.c_str());
    if (doc.HasParseError()) {
        CCLOG("Error Parse");
    } else {
        if (doc.IsObject() && doc.HasMember("student")) {
            rapidjson::Value &studentList = doc["student"];
            for (rapidjson::SizeType i = 0; i < studentList.Size(); i++) {
                CCLOG("Read file: Name = %s, age = %d, address = %s", studentList[i]["name"].GetString(), studentList[i]["age"].GetInt(), studentList[i]["address"].GetString());
            }
        }
    }
    return true;
}
