#include "MemBlockHeader.h"


MemBlockHeader::MemBlockHeader()
{
	this->statusEmpty = true;
	this->size = 0;
	this->startPoint = 0;
}

MemBlockHeader::MemBlockHeader(unsigned short startPoint)
{
	this->statusEmpty = true;
	this->size = 0;
	this->startPoint = startPoint;
}

MemBlockHeader::MemBlockHeader(unsigned short size, unsigned short startPoint)
{
	this->statusEmpty = true;
	this->size = size;
	this->startPoint = startPoint;
}

MemBlockHeader::MemBlockHeader(unsigned short size, unsigned short startPoint, bool statusEmpty)
{
	this->statusEmpty = statusEmpty;
	this->size = size;
	this->startPoint = startPoint;
}

MemBlockHeader::~MemBlockHeader()
{
}

bool MemBlockHeader::getStatusEmpty() const
{
	return statusEmpty;
}

unsigned short MemBlockHeader::getSize() const
{
	return size;
}

unsigned short MemBlockHeader::getStartPoint() const
{
	return startPoint;
}

void MemBlockHeader::changeStatusEmpty()
{
	statusEmpty = !statusEmpty;
}

void MemBlockHeader::setSize(unsigned short newSize)
{
	size = newSize;
}

void MemBlockHeader::setStartPoint(unsigned short newStartPoint)
{
	startPoint = newStartPoint;
}
