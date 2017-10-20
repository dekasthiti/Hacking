#pragma once
template <class T>
class SmartPointers {

	// Constructor: Basic, with a new object
	SmartPointers<t>(T* ptr)
	{
		ref = ptr;
		refCount = (size_t*)malloc(sizeof(size_t));  // Allocate & initialize refcount
		*refCount = 1;
	}

	// Constructor: Parameterized, create a new pointer with an existing object
	SmartPointers<T>(SmartPointers<T> &existingSptr)
	{
		ref = existingSptr;
		refCount = existingSptr.refCount;
		(*refCount)++;
	}

	// Constructor: Copy, with an existing object: overload equals operator
	SmartPointers<T> &operator=(SmartPointers &anotherSptr)
	{
		// If current pointer is already pointing to anoterSptr, do nothing, just return this
		if (this == &anotherSptr)
		{
			return *this;
		}
		// Reduce the current smart pointer's reference since it will be effectively killed by the assignment
		if (*refCount > 0)
		{
			remove();
		}

		// Update the reference count and ptr of the existing smart pointer
		refCount = anotherSptr.refCount;
		ref = anotherSptr;

		// Increment ref count because by assigning, you've added a reference.
		(*refCount)++;

		return *this; // why are we returning *this & not this? Because function signature has return type SmartPointers<T>&?
	}

	// Destructor: Calls remove(), which checks the ref count, if 0, deletes the ptr and releases the memory
	~SmartPointers()
	{
		remove();
	}

protected: //why?
	void remove()
	{
		(*refCount)--; // Always reduce refCount first, then check if it is zero. Will it make a difference if it is post or pre decrement?
		if (*refCount == 0)
		{
			delete ref;
			ref = NULL;

			free(refCount);  // because refcount was allocated by malloc
			refCount = NULL;
		}
	}

	// Data Members:
	T* sptr;			// smart pointer of type T
	size_t* refCount; // smart pointer reference count of type size_t. This is a pointer because ref count is tracked across multiple smart pointers to 1 obj

};