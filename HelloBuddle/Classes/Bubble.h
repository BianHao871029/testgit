/************************************************************************/
/* 
** Date  : 2013/9/20

** author: Bright Moon

** Note	 : 游戏中，泡泡类的组合，包含一些基本成员和函数
*/
/************************************************************************/


#ifndef _BUBBLE_H_
#define _BUBBLE_H_

#include "cocos2d.h"

#include "BubbleConstant.h"

using namespace cocos2d;

class Bubble : public cocos2d::Sprite
{
public:
	Bubble();
	~Bubble();

public:
	virtual bool init();
	CREATE_FUNC(Bubble);


public:
	void setBubbleColor(/*BUBBLE_COLOR*/ int Color);
	/*BUBBLE_COLOR*/ int getBubbleColor();

	void setRowIndex(int row);
	int getRowIndex();

	void setColumnIndex(int col);
	int getColumnIndex();
	bool initWithFile2(const std::string& filename);

	void setRowColIndex(int row, int col)
	{
		m_nRowIndex = row;
		m_nColIndex = col;
	}

	//BUBBLE_COLOR 
	int randomColor();		//随机生成一种颜色
	

private:
	//泡泡所有位置的行和列
	int m_nRowIndex;
	int m_nColIndex;

	/*BUBBLE_COLOR*/ int m_color;
};
#endif	//_BUBBLE_H_