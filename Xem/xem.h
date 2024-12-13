#include <stddef.h>
#include "core/Heap.h"

void test()
{
	getch();
	InitHeap();
	getch();
	DeInitHeap();
	getch();
}

void* alloc(size_t size)
{
	return NULL;
}

void free(void* ptr, size_t size)
{

}