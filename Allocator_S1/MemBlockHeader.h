#pragma once
class MemBlockHeader
{
	bool statusEmpty = true;
	unsigned short size = 0;
	unsigned short startPoint = 0;
public:
	MemBlockHeader();
	explicit MemBlockHeader(unsigned short startPoint);
	MemBlockHeader(unsigned short size, unsigned short startPoint);
	MemBlockHeader(unsigned short size, unsigned short startPoint, bool statusEmpty);
	~MemBlockHeader();

	bool getStatusEmpty() const;

	unsigned short getSize() const;

	unsigned short getStartPoint() const;

	void changeStatusEmpty();

	void setSize(unsigned short newSize);

	void setStartPoint(unsigned short newStartPoint);
};

