/**
 * malloc.h
 * Memory Allocator Base Class
 * */

/**
 * abstract base class MemoryAllocator
 * public methods:
 * - Constructor ( int _size ): initialize the allocator with size = _size
 * - malloc ( int size ): Allocate memory with size = size
 * - free ( int ptr, int size ): free size memory starting from ptr
 * private members:
 * - size: size of the memory
 * */
class MemoryAllocator
{
public:
	MemoryAllocator ( int _size ) : memory_size ( _size ) {}

	virtual int malloc ( int size ) = 0;
	virtual int free ( int ptr, int size ) = 0;

private:
	int memory_size;
}