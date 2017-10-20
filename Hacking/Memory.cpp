#include "Memory.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void * alignedMalloc(size_t size, unsigned alignment)
{
	// 1. Compute total memory required to return aligned memory
	size_t extra = (alignment - 1) + sizeof(void*);  // sizeof(void*) is for book-keeping
	size_t alignedSize = size + extra;
	void* origPtr;
	void* alignedPtr;
	//void  (* metaAlignedPtr)[2]; // array of void* is not allowed!
	void** metaAlignedPtr;

	// 2. Request for memory
	origPtr = (void*)malloc(alignedSize);
	if (origPtr != NULL)
	{
		// 3. Get a pointer to the aligned address
		alignedPtr = (void*)( ( ( size_t)(origPtr) + extra ) & ~( alignment - 1) ); // mask out the lsbs to align with alignment request
	}
	else
	{
		return nullptr;
	}

	// 4. Actual bookkeeping of the original pointer and the aligned pointer
	//metaAlignedPtr[0] = alignedPtr; // Runtime error: metaAlignedPtr[0] is being used without being initialized
	
	metaAlignedPtr = &alignedPtr; 

	metaAlignedPtr[-1] = origPtr;  // this will be required when we need to free the aligned + extra memory, but get Runtime error: "Stack around aligned pointer is corrupt"

	//(&alignedPtr)[-1] = origPtr;
	return metaAlignedPtr[0];
}

void alignedFree(void * ptr)
{
	void** metaAlignedPtr = (void**)&ptr;
	void* origPtr = metaAlignedPtr[-1];

	if (origPtr != NULL)
	{
		free(origPtr);
		origPtr = NULL;
	}

}

int main_Memory()
{
	size_t size;
	unsigned alignment;
	cout << "How much memory do you need? (In bytes, please!) " << endl;
	cin >> size;
	cout << "What are your alignment needs? (In bytes, please!) " << endl;
	cin >> alignment;

	cout << "Submitting request for " << size << "bytes at " << alignment << "bytes..." << endl;
	void* alignedPtr;
	if ((alignedPtr = alignedMalloc(size, alignment)) != NULL)
	{
		cout << " Aligned memory allocated at " << alignedPtr << "!!" << endl;
	}
	else
	{
		cout << "Aligned memory couldn't be allocated :(" << endl;
	}

	cout << "Let's check if we can track the original pointer ..." << endl;
	void** metaPointer = &alignedPtr;    // here alignedPtr's address is different from the address in the alignedMalloc()
	void* origPointer = metaPointer[-1];

	if (origPointer != NULL)
	{
		cout << "Original pointer is: " << origPointer;  // Gets 0xcccc which is not null, but not right either
	}
	else
	{
		cout << "Can't get to original pointer :(";
	}

	//free(alignedPtr);

	return 0;
}
