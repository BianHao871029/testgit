#include "StartLayer.h"
#include "BubbleConstant.h"
#include "GameScene.h"
#include <string>
using namespace std;
using namespace cocos2d;
StartLayer::StartLayer()
{
	SimpleAudioEngine::getInstance()->playBackgroundMusic("main_music.mp3", true);
}

StartLayer::~StartLayer()
{
}
Scene* StartLayer::scene()
{
    Scene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = Scene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        StartLayer *layer = StartLayer::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}
bool StartLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());
		Size winSize=Director::getInstance()->getWinSize();
		////labelttf *label1=labelttf::create("new game","arial",24*2);
		////menuitemlabel *pmenuitem = menuitemlabel::create(label1, this, menu_selector(startlayer::startgamecallback));
		////pmenuitem->settag(1);
		////pmenuitem->setposition(winsize.width / 2, winsize.height / 2);

        //Menu* pMenu = Menu::create(pMenuItem, NULL);
        //pMenu->setPosition(Vec2(0,0));
        //CC_BREAK_IF(! pMenu);
        //this->addChild(pMenu, 1);

		auto newGameItem = MenuItemImage::create("newgameA.png",
                                             "newgameB.png",
                                             CC_CALLBACK_1(StartLayer::startGameCallback, this));
		//newGameItem->setScale(0.5);
		newGameItem->setPosition(Point(winSize.width / 2, winSize.height / 2 - newGameItem->getContentSize().height*1));
		newGameItem->setEnabled(true);


		LabelTTF* pLabel = LabelTTF::create("Bubble Cat 2014", "Arial", 24 * 3);
        CC_BREAK_IF(! pLabel);
        pLabel->setPosition(Vec2(winSize.width / 2, winSize.height - 50));
        this->addChild(pLabel, 1);

        Sprite* pSprite = Sprite::create("StartScene_CN.jpg");
        CC_BREAK_IF(! pSprite);
        pSprite->setPosition(Vec2(winSize.width/2, winSize.height/2));
       // this->addChild(pSprite, 0);

		auto closeItem = MenuItemImage::create(
												"CloseNormal.png",
												"CloseSelected.png",
												CC_CALLBACK_1(StartLayer ::menuCloseCallback, this));
    
		closeItem->setPosition(Vec2(winSize.width - closeItem->getContentSize().width/2 ,
									closeItem->getContentSize().height/2));

		// create menu, it's an autorelease object
		auto menu = Menu::create(closeItem,newGameItem, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 2);
		this->setVector();
        bRet = true;
	}while(0);
	return bRet;
}
void StartLayer::setVector()
{
	//Vector<Sprite*> InterList;
	std::vector<std::string> searchPaths;
	searchPaths.push_back("hd");
    searchPaths.push_back("ccs-res/hd");
    searchPaths.push_back("ccs-res/hd/scenetest");
    searchPaths.push_back("ccs-res/hd/scenetest/ArmatureComponentTest");
	log("the InterList length is %d",searchPaths.size());
	log("the InterList length is %d",searchPaths.max_size());

}
void StartLayer::menuCloseCallback(Ref * pSender)
{
	Director::getInstance()->end();

}
void StartLayer::startGameCallback(Ref * pSender)
{
	Director::getInstance()->replaceScene(GameScene::scene());
}
