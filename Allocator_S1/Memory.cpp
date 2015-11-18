#include "Memory.h"
#include <string>

//using namespace std;

Memory::Memory()
{
	this->memorySize = 2048;
	this->listOfHeaders.push_back(MemBlockHeader(this->memorySize, 0));
	this->startPtr = new int[this->memorySize];
}
														
Memory::Memory(unsigned short memorySize)
{
	this->memorySize = memorySize;
	this->listOfHeaders.push_back(MemBlockHeader(memorySize, 0));
	this->startPtr = new int[memorySize/4];
}

Memory::~Memory()
{
	delete[] this->startPtr;
}

void * Memory::mem_alloc(size_t size)
{
	if (size <= 0)
	{
		return NULL;
	}
	list<MemBlockHeader>::iterator iter;
	for (iter = this->listOfHeaders.begin(); iter != this->listOfHeaders.end(); ++iter)
	{
		if (iter->getStatusEmpty() && (iter->getSize()) >= size)
		{
			unsigned short busySize = this->returnAllocSize(size + 1) * 4;
			unsigned short freeSize = iter->getSize() - busySize;
			unsigned short tempPoint = iter->getStartPoint();
			iter = this->listOfHeaders.erase(iter);
			this->listOfHeaders.insert(iter, MemBlockHeader(busySize, tempPoint, false));
			this->listOfHeaders.insert(iter, MemBlockHeader(freeSize, tempPoint + busySize));
			this->combineAndNext(--iter);
			void *ptr = this->startPtr + tempPoint / 4;
			return ptr;
		}
	}
	return NULL;
}

void * Memory::mem_realloc(void * addr, size_t size)
{
	if (!addr)
	{
		return mem_alloc(size);
	}
	size_t startPoint = (size_t)addr - (size_t)this->startPtr;
	if (size < 0 || startPoint < 0 || startPoint >= this->memorySize)
	{
		return NULL;
	}
	if (size == 0)
	{
		this->mem_free(addr);
		return addr;
	}
	unsigned short ptr = (unsigned short)startPoint;
	list<MemBlockHeader>::iterator iter;
	for (iter = this->listOfHeaders.begin(); iter != this->listOfHeaders.end(); ++iter)
	{
		if (iter->getStartPoint() == ptr)
		{
			if (iter->getSize() == size + 1 || (iter->getSize() / 4 == (size + 1) / 4 + 1 && iter->getSize() < (size + 1) + 4))
			{
				return addr;
			}
			if (iter->getSize() > size + 1)
			{
				unsigned short busySize = this->returnAllocSize(size + 1) * 4;
				unsigned short freeSize = iter->getSize() - busySize;
				iter->setSize(busySize);
				unsigned short tempPoint = iter->getStartPoint() + busySize;
				listOfHeaders.insert(++iter, MemBlockHeader(freeSize, tempPoint));
				this->combineAndNext(--iter);
				return addr;
			}
			/* New size is bigger, then the previous one */
			void *p1 = this->mem_alloc(size);
			if (!p1)
			{
				return NULL;
			}
			this->mem_free(addr);
			return p1;
		}
	}
	return NULL;
}

void Memory::mem_free(void * addr)
{
	size_t startPoint = (size_t)addr - (size_t)this->startPtr;
	if (startPoint < 0 || startPoint >= this->memorySize)
	{
		return;
	}
	unsigned short ptr = (unsigned short)startPoint;
	list<MemBlockHeader>::iterator iter;
	for (iter = this->listOfHeaders.begin(); iter != this->listOfHeaders.end(); ++iter)
	{
		if (iter->getStartPoint() == ptr)
		{
			iter->changeStatusEmpty();
			iter = this->combineAndNext(iter);
			iter = this->combineAndPrev(iter);
			return;
		}
	}
}

list<MemBlockHeader>::iterator Memory::combineAndNext(list<MemBlockHeader>::iterator pointer)
{
	if (pointer->getStatusEmpty() && (++pointer != this->listOfHeaders.end()) && (pointer--)->getStatusEmpty())
	{
		return combineTwo(pointer);
	}
	return pointer;
}

list<MemBlockHeader>::iterator Memory::combineAndPrev(list<MemBlockHeader>::iterator pointer)
{
	if (pointer->getStatusEmpty() && (pointer-- != this->listOfHeaders.begin()) && pointer->getStatusEmpty())
	{
		return combineTwo(pointer);
	}
	return pointer++;
}

list<MemBlockHeader>::iterator Memory::combineTwo(list<MemBlockHeader>::iterator pointer)
{
	unsigned short startPoint = pointer->getStartPoint();
	unsigned short upSize = pointer->getSize();
	pointer = this->listOfHeaders.erase(pointer);
	pointer->setSize(pointer->getSize() + upSize);
	pointer->setStartPoint(startPoint);
	return pointer;
}

string Memory::mem_dump()
{
	string outString;
	outString = "N  Pointer  Size  Status\n";
	unsigned short i = 0;
	for (auto thead:this->listOfHeaders)
	{
		outString += std::to_string(i) + "    " + std::to_string(thead.getStartPoint()) + "      " +
			std::to_string(thead.getSize()) + "   " + 
			(thead.getStatusEmpty() ? "free\n" : "busy\n");
		++i;
	}
	return outString;
}
