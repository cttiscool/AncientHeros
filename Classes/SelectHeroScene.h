//
//  SelectHeroScene.h
//  AncientHeros
//
//  Created by mac on 14-4-28.
//
//

#ifndef __AncientHeros__SelectHeroScene__
#define __AncientHeros__SelectHeroScene__

#include "cocos2d.h"

class SelectHeroScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(SelectHeroScene);
};

#endif /* defined(__AncientHeros__SelectHeroScene__) */
