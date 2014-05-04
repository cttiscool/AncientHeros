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

    //start button
    auto startItem = MenuItemFont::create("Start",
                                           CC_CALLBACK_1(HomeScene::menuCloseCallback, this));
	/*startItem->setPosition(Point(origin.x + visibleSize.width/2,
                                 origin.y + visibleSize.height - startItem->getContentSize().height - 20));*/
    
    //handbook button
    auto handbookItem = MenuItemFont::create("HandBook",
                                          CC_CALLBACK_1(HomeScene::menuCloseCallback, this));
	handbookItem->setPosition(Point(startItem->getPositionX(),
                                 startItem->getPositionY() - 60));

    //add menu
    auto menu = Menu::create(startItem, handbookItem, NULL);
    menu->setPosition(Point(origin.x + visibleSize.width/2, visibleSize.height));
    this->addChild(menu, 1);

    // add menu animation
    menu->runAction(EaseElasticOut::create(MoveBy::create(1.8f, Point(0, -200))));

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
