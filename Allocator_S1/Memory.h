#pragma once

#include <list>
#include "MemBlockHeader.h"

using namespace std;

class Memory
{
	unsigned short memorySize = 2048;
	list <MemBlockHeader> listOfHeaders;
	int *startPtr = nullptr;

	static int inline returnAllocSize(unsigned short whatIsLower);

	list<MemBlockHeader>::iterator combineAndNext(list<MemBlockHeader>::iterator pointer);
	list<MemBlockHeader>::iterator combineAndPrev(list<MemBlockHeader>::iterator pointer);
	list<MemBlockHeader>::iterator combineTwo(list<MemBlockHeader>::iterator pointer);

public:
	Memory();
	explicit Memory(unsigned short memorySize);
	~Memory();

	void * mem_alloc(size_t size);
	void * mem_realloc(void * addr, size_t size);
	void mem_free(void * addr);
	string mem_dump();
};

