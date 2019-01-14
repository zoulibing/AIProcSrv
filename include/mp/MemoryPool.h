#pragma once
#include <vector>
#include "MemoryChunk.h"
#include "Mutex.h"

class IMemoryPool
{
public:
        IMemoryPool();
        ~IMemoryPool();

	enum
	{
		MIN_SIZE = sizeof(MemoryBlock*),
		MAX_SIZE = 1024
	};

	void* malloc(size_t size);
	void free(void* memory);
	void report();
protected:
	void initChunks();
	void clear();
	MemoryChunk* matchChunk(size_t size);
protected:
	std::vector<MemoryChunk*> m_chunks;
	Mutex m_mutex;
};
