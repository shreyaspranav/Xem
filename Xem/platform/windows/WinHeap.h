
// Only work if the target platform is Windows.
#ifdef _WIN32
#include <windows.h>

inline void* __AllocateWindowsHeap(size_t heapSize)
{
	// NOTE: There is no built in support for reallocation for VirtualAlloc.
	// NOTE: The memory will be zero initialized.
	// NOTE: The size of the allocated block will be overestimated to the boundary of the next page.

	LPVOID heapAddress = VirtualAlloc(
		NULL,                             // NULL, To let the OS decide the starting address of the block
		heapSize,                         // The size of the block, usually large because the same block cannot be reallocated
		MEM_RESERVE | MEM_COMMIT,         // Reserve and commit the block so that the memory can be readily used
		PAGE_READWRITE                    // Provide read and write access
	);

	return heapAddress;
}

inline int __FreeWindowsHeap(void* address)
{
	// Pass 0 to release an entire block of memory
	// Size can only be passed to decommit the part of the block

	return VirtualFree(address, 0, MEM_RELEASE);
}

#endif // _WIN32
