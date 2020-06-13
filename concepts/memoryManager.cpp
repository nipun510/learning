#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stdexcept>
#include <sstream>

const int DEFAULT_MEM_SIZE = 1e2;

/*
    memAllocator is custom memory manager class. It creates a pool of memory and manages it for the managed class.
    All the objects of a managed class share a common allocator.
    Managed class implements overloaded new and delete operator to make use of the memory manager.
*/

class memAllocator {
    private:
    struct memory {
        void* memptr;
        size_t size;
        memory(void* ptr, size_t val) {
            memptr = ptr;
            size = val;
        }
        bool operator < (const memory & mem) {
            return size < mem.size;
        }
    };
    
    public:
    memAllocator (const int total = DEFAULT_MEM_SIZE){
        _total = total;
        void *ptr = malloc(_total);
        _freeMemoryHandles.push(new memory(ptr, _total));
        _rem = _total;
    }
    
    void* allocate(size_t elementsCount) {
        size_t requiredValue = sizeof(char) * elementsCount;
        if (_freeMemoryHandles.empty() || _freeMemoryHandles.top()->size < requiredValue) {
            std::ostringstream oss;
            size_t maxSize = _freeMemoryHandles.empty() ? 0 : _freeMemoryHandles.top()->size;
            oss << "value too large. " << "Max memory size that can be allocated is " << maxSize << ".";
            
            throw std::runtime_error(oss.str().c_str());
        }
        
        memory *maxMemoryHandle = _freeMemoryHandles.top();
        _freeMemoryHandles.pop();
        if (maxMemoryHandle->size > requiredValue) {
            void *remMemoryHandle = static_cast<char *>(maxMemoryHandle->memptr) + requiredValue;
            _freeMemoryHandles.push(new memory(remMemoryHandle, maxMemoryHandle->size - requiredValue));
        }
        _rem -= requiredValue;
        _allocatedMemorySizes[maxMemoryHandle->memptr] = requiredValue;
        std::cout << "allocating mem address [" << maxMemoryHandle->memptr << "] of size [" << requiredValue << "]\n";
        return maxMemoryHandle->memptr;
    }
    
    void deallocate(void *ptr, size_t givenSize) {
        if (ptr == NULL) {
            return;
        }
        std::cout << "freeing memory addr [" << ptr << "]\n";
        if (_allocatedMemorySizes.find(ptr) == _allocatedMemorySizes.end()) {
            throw std::runtime_error("invalid free");
        }
        size_t allocatedSize = _allocatedMemorySizes[ptr];
        if ( allocatedSize != givenSize) {
            throw std::runtime_error("cannot free partially allocated memory");
        }
        _allocatedMemorySizes.erase(ptr);
        _freeMemoryHandles.push(new memory(ptr, allocatedSize));
        return;
    }
    void deallocateAll() {
        while(!_allocatedMemorySizes.empty()) {
            deallocate(_allocatedMemorySizes.begin()->first, _allocatedMemorySizes.begin()->second);
        }
    }
    
    private:
    std::priority_queue<memory*> _freeMemoryHandles;
    std::unordered_map<void *, size_t> _allocatedMemorySizes;
    size_t _rem;
    size_t _total;
};


template<typename Allocator = std::allocator<char>>
class memManagedClass {
    public:
    memManagedClass() {
    }
    
    void * operator new(size_t s) {
        void *ptr = allocator.allocate(s);
        return ptr;
    }

    void operator delete(void *p){
      allocator.deallocate(static_cast<char *>(p), sizeof(memManagedClass));
    }
    
    static bool destroyAllObjects() {
      allocator.deallocateAll();
      return true;
    }
    
    int val, val1;
    static Allocator allocator;
};

template<typename T>
T memManagedClass<T>::allocator;



using managedClass = memManagedClass<memAllocator>;
        

int main() {
    try {

        managedClass *obj1 = new managedClass();
        managedClass *obj2 = new managedClass();
        //delete (obj1);
        //delete (obj2);
        std::cout << "obj1 => [" << obj1 << "], obj2 => [" << obj2 << "]\n";
        managedClass::destroyAllObjects();
        return 0;
    }  catch (const std::exception & e) {
        std::cout << e.what() << std::endl;
    }
   
}
