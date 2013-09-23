#include "HelloWorldScene.h"
#include "cocos2d.h"
using namespace cocos2d;

CCSize temp;
CCSprite* gSprite;
char grossini[] = ("grossini_dance_01.png");

CCScene* HelloWorld::scene()
{
	CCScene * scene = NULL;
	do 
	{
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		HelloWorld * layer = HelloWorld::create();
		CC_BREAK_IF(! layer);

		scene->addChild(layer);
	} while (0);

	return scene;
}

bool HelloWorld::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(! CCLayer::init());

		// get window size
		CCSize size = CCDirector::sharedDirector()->getWinSize();

		// close button
		CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
			"CloseNormal.png",
			"CloseSelected.png",
			this,
			menu_selector(HelloWorld::menuCloseCallback));
		CC_BREAK_IF(! pCloseItem);

		pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

		CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! pMenu);

		this->addChild(pMenu, 1);

		// forward button
		CCMenuItemImage *buttonForward = CCMenuItemImage::create(
			"f1.png",
			"f2.png",
			this,
			menu_selector(HelloWorld::menuForwardCallback));
		CC_BREAK_IF(! buttonForward);

		buttonForward->setPosition(ccp(size.width-100, 100));

		CCMenu *forwardMenu = CCMenu::create(buttonForward, NULL);
		forwardMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! forwardMenu);

		this->addChild(forwardMenu, 1);

		// back button
		CCMenuItemImage *buttonBack = CCMenuItemImage::create(
			"b1.png",
			"b2.png",
			this,
			menu_selector(HelloWorld::menuBackCallback));
		CC_BREAK_IF(! buttonBack);

		buttonBack->setPosition(ccp(100, 100));

		CCMenu *backMenu = CCMenu::create(buttonBack, NULL);
		backMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! backMenu);

		this->addChild(backMenu, 1);

		// play button
		CCMenuItemImage *buttonPlay = CCMenuItemImage::create(
			"btn-play-normal.png",
			"btn-play-selected.png",
			this,
			menu_selector(HelloWorld::menuPlayCallback));
		CC_BREAK_IF(! buttonPlay);

		buttonPlay->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2, 50));

		CCMenu *playMenu = CCMenu::create(buttonPlay, NULL);
		playMenu->setPosition(CCPointZero);
		CC_BREAK_IF(! playMenu);

		this->addChild(playMenu, 1);

		// label
		CCLabelTTF* pLabel = CCLabelTTF::create("Grossini Dance", "Arial", 24);
		CC_BREAK_IF(! pLabel);

		pLabel->setPosition(ccp(size.width / 2, size.height - 50));

		this->addChild(pLabel, 1);

		// image
		gSprite = CCSprite::create(grossini);
		CC_BREAK_IF(! gSprite);

		gSprite->setPosition(ccp(size.width/2, size.height/2));

		this->addChild(gSprite, 0);

		bRet = true;
	} while (0);

	return bRet;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
	// close button clicked
	CCDirector::sharedDirector()->end();
}

void HelloWorld::menuForwardCallback(CCObject* pSender)
{
	// forward button clicked
	if((grossini[15]=='0' && grossini[16]<'9') || (grossini[15]=='1' && grossini[16]<'4'))
	{
		grossini[16]++;
	}
	else if(grossini[15]=='0' && grossini[16]=='9')
	{
		grossini[15] = '1';
		grossini[16] = '0';
	}
	else if(grossini[15]=='1' && grossini[16]=='4')
	{
		grossini[15] = '0';
		grossini[16] = '1';
	}
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	this->removeChild(gSprite);
	gSprite = CCSprite::create(grossini);
	gSprite->setPosition(ccp(size.width/2, size.height/2));
	this->addChild(gSprite, 0);
}

void HelloWorld::menuBackCallback(CCObject* pSender)
{
	// back button clicked
	if((grossini[15]=='0' && grossini[16]>'1') || (grossini[15]=='1' && grossini[16]>='1'))
	{
		grossini[16]--;
	}
	else if(grossini[15]=='0' && grossini[16]=='1')
	{
		grossini[15] = '1';
		grossini[16] = '4';
	}
	else if(grossini[15]=='1' && grossini[16]=='0')
	{
		grossini[15] = '0';
		grossini[16] = '9';
	}
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	this->removeChild(gSprite);
	gSprite = CCSprite::create(grossini);
	gSprite->setPosition(ccp(size.width/2, size.height/2));
	this->addChild(gSprite, 0);
}

void HelloWorld::menuPlayCallback(CCObject* pSender)
{
	// play button clicked
}