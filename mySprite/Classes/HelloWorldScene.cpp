#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* HelloWorld::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // Create Scene
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // Create Layer
        HelloWorld *layer = HelloWorld::create();
        CC_BREAK_IF(! layer);

        // Layer as Scene Child
        scene->addChild(layer);
    } while (0);

    // Return the Scene
    return scene;
}

bool HelloWorld::init()
{
    bool bRet = false;
    do 
    {
        // Super Initialize
        CC_BREAK_IF(! CCLayer::init());

        // Close Button - Creating
        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(HelloWorld::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

		/* CLOSE BUTTON */

        // Close Button - Placing
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));
        
		// Close Button - Invoke Menu
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);
        
		// Close Button - Add as Layer
        this->addChild(pMenu, 1);

		/* TEXT LABEL */

        // Text Label - Creating
        CCLabelTTF* pLabel = CCLabelTTF::create("TERATOMAN", "Arial", 18);
        CC_BREAK_IF(! pLabel);
        
		// Text Label - Placing
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));
        
		// Text Label - Add as Layer
        this->addChild(pLabel, 1);

		/* SPLASH IMAGE */

        // Splash Image - Creating
        CCSprite* pSprite = CCSprite::create("Teratoman.jpg");
        CC_BREAK_IF(! pSprite);
        
		// Splash Image - Placing
        pSprite->setPosition(ccp(size.width/2, size.height/2));
        
		// Splash Image - Add as Layer
        this->addChild(pSprite, 0);

        bRet = true;
    } while (0);

    return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    // Close Button - Clicked
    CCDirector::sharedDirector()->end();
}

