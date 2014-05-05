//
//  SelectHeroScene.cpp
//  AncientHeros
//
//  Created by mac on 14-4-28.
//
//

#include "SelectHeroScene.h"
#include "MobClickCpp.h"


USING_NS_CC;

Scene* SelectHeroScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = SelectHeroScene::create();
    
    scene->addChild(layer);

    return scene;
}

bool SelectHeroScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    auto label = LabelTTF::create("select", "Arial", 32);
    label->setPosition(Point(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    
    return true;
    
}

void SelectHeroScene::onEnter(){
    Layer::onEnter();
    MobClickCpp::beginLogPageView("SelectHeroScene");
}

void SelectHeroScene::onExit(){
    Layer::onExit();
    MobClickCpp::endLogPageView("SelectHeroScene");
}