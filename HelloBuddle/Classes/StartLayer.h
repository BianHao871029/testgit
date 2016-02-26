#ifndef __StartLayer_H__
#define __StartLayer_H__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion ;

class StartLayer:public cocos2d::Layer
{
public:
	StartLayer();
	~StartLayer();
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::Scene* scene();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void startGameCallback(cocos2d::Ref* pSender);
	void setVector();
	CREATE_FUNC(StartLayer);

};
#endif //__StartLayer_H__