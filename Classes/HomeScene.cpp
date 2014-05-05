#include "HomeScene.h"
#include "SelectHeroScene.h"
#include "MobClickCpp.h"

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
    //handbook button
    auto handbookItem = MenuItemFont::create("HandBook",
                                          CC_CALLBACK_1(HomeScene::menuCloseCallback, this));

    //add menu
    auto menu = Menu::create(startItem, handbookItem, NULL);
    menu->setPosition(Point(origin.x + visibleSize.width/2, visibleSize.height));
    menu->alignItemsVertically();
    this->addChild(menu, 1);

    // add menu animation
    menu->runAction(EaseElasticOut::create(MoveBy::create(1.8f, Point(0, -200))));

    //setting menu
    auto settingItem = MenuItemFont::create("Setting",CC_CALLBACK_1(HomeScene::menuSettingCallback, this));
    auto musicItem = MenuItemFont::create("Music",CC_CALLBACK_1(HomeScene::menuSettingCallback, this));
    auto feedbackItem = MenuItemFont::create("Feedback",CC_CALLBACK_1(HomeScene::menuSettingCallback, this));
    auto castItem = MenuItemFont::create("Cast",CC_CALLBACK_1(HomeScene::menuSettingCallback, this));

    settingItem->setTag(0);
    musicItem->setTag(1);
    feedbackItem->setTag(2);
    castItem->setTag(3);

    settingMenu = Menu::create(settingItem, musicItem, feedbackItem, castItem, NULL);
    settingMenu->setAnchorPoint(Point(0, 0));
    settingMenu->setPosition(Point(50, 50));
    this->addChild(settingMenu);

    return true;
}

void HomeScene::menuSettingCallback(Ref* pSender)
{
    int n = 0;
    int b;
    hasMenuSpread ? b = -1: b=1;

    auto tempItem = settingMenu->getChildByTag(0);
    do {
        tempItem->runAction(MoveBy::create(0.5f, Point(b* 50 * n, 0)));
        n++;
        tempItem = settingMenu->getChildByTag(n);
    } while (tempItem != NULL);

    hasMenuSpread = !hasMenuSpread;
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

void HomeScene::onEnter(){
    Layer::onEnter();
    MobClickCpp::beginLogPageView("HomeScene");
}

void HomeScene::onExit(){
    Layer::onExit();
    MobClickCpp::endLogPageView("HomeScene");
}
