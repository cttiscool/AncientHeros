#include "HomeScene.h"
#include "SelectHeroScene.h"

USING_NS_CC;

Scene* HomeScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HomeScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HomeScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    Director::getInstance()->setContentScaleFactor(1);

    auto closeItem = MenuItemFont::create("Start",
                                           CC_CALLBACK_1(HomeScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width/2,
                                 origin.y + visibleSize.height - closeItem->getContentSize().height));
    
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}


void HomeScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    auto selectHeroScene = SelectHeroScene::createScene();
    Director::getInstance()->replaceScene(selectHeroScene);

/*#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif*/
}
