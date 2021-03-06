#include<iostream>
#include<memory>

struct AllocationMemory
{
    uint32_t MemoryAllocated;
    uint32_t MemoryFree;

    uint32_t CurrentUsage() {
        return MemoryAllocated - MemoryFree;
    }

};
static AllocationMemory s_AllocationMemory;
void* operator new(size_t size)
{
    s_AllocationMemory.MemoryAllocated += size;
    return malloc(size);
}
void operator delete(void*  memory, size_t size)
{
    s_AllocationMemory.MemoryFree += size;
    free(memory);
}

static void MemoryTotalUsed()
{
    std::cout << "Memory Usage" << s_AllocationMemory.CurrentUsage() << std::endl;
}
struct object
{
    int x;
    float y;
    char z;

};


int main()
{
    MemoryTotalUsed();
    std::string name= "Anurag sdsdfsdfsdsfsdfsdfsdfsfsdfsdfdsdfsfdfdsdssdfsdfsdfsdsfdsfdddsdssdfdsdsfsd";
    MemoryTotalUsed();
    {
        MemoryTotalUsed();
        std::unique_ptr<object> a = std::make_unique<object>();  
        MemoryTotalUsed();
    }
    MemoryTotalUsed();
      

}