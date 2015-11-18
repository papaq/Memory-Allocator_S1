#pragma once
class MemBlockHeader
{
	bool statusEmpty = true;
	unsigned short size = 0;
	unsigned short startPoint = 0;
public:
	MemBlockHeader();
	MemBlockHeader(unsigned short startPoint);
	MemBlockHeader(unsigned short size, unsigned short startPoint);
	MemBlockHeader(unsigned short size, unsigned short startPoint, bool statusEmpty);
	~MemBlockHeader();

	bool inline getStatusEmpty(){
		return statusEmpty;
	}

	unsigned short inline getSize(){
		return size;
	}

	unsigned short inline getStartPoint(){
		return startPoint;
	}

	void inline changeStatusEmpty(){
		statusEmpty = !statusEmpty;
	}

	void inline setSize(unsigned short newSize)
	{
		size = newSize;
	}

	void inline setStartPoint(unsigned short newStartPoint)
	{
		startPoint = newStartPoint;
	}
};

