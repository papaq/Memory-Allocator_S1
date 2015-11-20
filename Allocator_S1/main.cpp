#include <iostream>
#include <string>

#include "Memory.h"

using namespace std;

int main()
{
	auto Me = Memory(2048);
	cout << Me.mem_dump() << endl;
	Me.mem_alloc(10);
	cout << Me.mem_dump() << endl;
	auto p1 = Me.mem_alloc(16);
	cout << Me.mem_dump() << endl;
	auto p2 = Me.mem_alloc(15);
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
