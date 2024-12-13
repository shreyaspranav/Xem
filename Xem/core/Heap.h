#include "platform/windows/WinHeap.h"

// The fixed size of the heap allocated in bytes: ----------------------------
#define HEAP_SIZE 1024 * 1024 * 512               // 512 MB
// ---------------------------------------------------------------------------

struct HeapState
{
	void* heapBlockAddr;
	size_t heapBlockSize;

}heapState;


void InitHeap()
{
	// Initialize the struct:
	heapState.heapBlockAddr = NULL;
	heapState.heapBlockSize = 0;

	void* heapAddr = NULL;

#ifdef _WIN32
	heapAddr = __AllocateWindowsHeap(HEAP_SIZE);
#endif // _WIN32

	if (heapAddr)
	{
		// Allocation Successful

		heapState.heapBlockAddr = heapAddr;
		heapState.heapBlockSize = HEAP_SIZE;
	}
	else 
	{
		printf("Allocation Failed!\n");
		// Allocation failed.
	}
}

void DeInitHeap()
{
	int status = 0;
#ifdef _WIN32
	status = __FreeWindowsHeap(heapState.heapBlockAddr);
#endif // _WIN32

	if (status)
	{
		heapState.heapBlockAddr = NULL;
		heapState.heapBlockSize = 0;
	}
	else
	{
		// Deallocation failed.
	}
}