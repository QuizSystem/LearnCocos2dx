#ifndef __NETWORKJSON_SCENE_H__
#define __NETWORKJSON_SCENE_H__

#include "cocos2d.h"
#include "network/HttpClient.h"

using namespace cocos2d;

class NetworkJson : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void onCompleteHttpRequest(network::HttpClient *sender, network::HttpResponse *reponse);
    
    // implement the "static create()" method manually
    CREATE_FUNC(NetworkJson);
};

#endif // __NETWORKJSON_SCENE_H__
