#include <iostream>
#include <string>
#include <list>

#include "Memory.h"

using namespace std;

int main()
{
	Memory Me = Memory(2048);
	cout << Me.mem_dump() << endl;
	Me.mem_alloc(10);
	cout << Me.mem_dump() << endl;
	void *p1 = Me.mem_alloc(16);
	cout << Me.mem_dump() << endl;
	void *p2 = Me.mem_alloc(15);
	cout << Me.mem_dump() << endl;
	Me.mem_alloc(10);
	cout << Me.mem_dump() << endl;
	Me.mem_free(p1);
	cout << Me.mem_dump() << endl;
	//Me.mem_free(p2);
	//cout << Me.mem_dump() << endl;
	Me.mem_alloc(11);
	cout << Me.mem_dump() << endl;

	Me.mem_realloc(p2, 15);
	cout << Me.mem_dump() << endl;
	Me.mem_realloc(p2, 13);
	cout << Me.mem_dump() << endl;
	Me.mem_realloc(p2, 11);
	cout << Me.mem_dump() << endl;
	Me.mem_realloc(p2, 18);
	cout << Me.mem_dump() << endl;
}

