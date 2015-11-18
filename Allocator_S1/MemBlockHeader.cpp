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
