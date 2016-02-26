#include "Bubble.h"

Bubble::Bubble()
{
	
}

Bubble::~Bubble()
{
}



bool Bubble::init()
{
	m_color = COLOR_COUNT;
	m_nRowIndex = -1;
	m_nColIndex = -1;
	return true;
}

void Bubble::setBubbleColor(/*BUBBLE_COLOR*/ int color)
{
	m_color = color;
}

/*BUBBLE_COLOR*/ int  Bubble::getBubbleColor()
{
	return m_color;
}

void Bubble::setRowIndex(int row)
{
	m_nRowIndex = row;
}

int Bubble::getRowIndex()
{
	return m_nRowIndex;
}

void Bubble::setColumnIndex(int col)
{
	m_nColIndex = col;
}

int Bubble::getColumnIndex()
{
	return m_nColIndex;
}

/*BUBBLE_COLOR*/ int Bubble::randomColor()
{
	//m_color= static_cast<BUBBLE_COLOR>(rand() % COLOR_COUNT);
	//m_color=rand() % COLOR_COUNT;
	m_color=random(0,7);
	return m_color;
}

bool Bubble::initWithFile2(const std::string& filename)
{
    CCASSERT(filename.size()>0, "Invalid filename for sprite");

    Texture2D *texture = Director::getInstance()->getTextureCache()->addImage(filename);
    if (texture)
    {
        Rect rect = Rect::ZERO;
        rect.size = texture->getContentSize();
        return initWithTexture(texture, rect);
    }

    // don't release here.
    // when load texture failed, it's better to get a "transparent" sprite then a crashed program
    // this->release();
    return false;
}