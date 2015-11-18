#pragma once

#include <list>
#include "MemBlockHeader.h"

using namespace std;

class Memory
{
	unsigned short memorySize;
	list <MemBlockHeader> listOfHeaders;
	int *startPtr = NULL;

	int inline returnAllocSize(unsigned short whatIsLower)
	{
		return whatIsLower % 4 == 0 ? whatIsLower / 4 : whatIsLower / 4 + 1;
	}

	list<MemBlockHeader>::iterator combineAndNext(list<MemBlockHeader>::iterator pointer);
	list<MemBlockHeader>::iterator combineAndPrev(list<MemBlockHeader>::iterator pointer);
	list<MemBlockHeader>::iterator combineTwo(list<MemBlockHeader>::iterator pointer);

public:
	Memory();
	Memory(unsigned short memorySize);
	~Memory();

	void * mem_alloc(size_t size);
	void * mem_realloc(void * addr, size_t size);
	void mem_free(void * addr);
	string mem_dump();
};

