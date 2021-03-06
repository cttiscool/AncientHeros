#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <UIButton.h>

class HomeScene : public cocos2d::Layer
{
public:
    cocos2d::Menu *settingMenu;
    bool hasMenuSpread;

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onEnter();
    virtual void onExit();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    //setting menu item click
    void menuSettingCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HomeScene);
};

#endif // __HELLOWORLD_SCENE_H__
