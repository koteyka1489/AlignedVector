#include "AlignedAllocator.h"
#include <initializer_list>

template <typename T>
class AVector
{
public:
    AVector(T data)
    {
        DataPtr = static_cast<T*>(AllocatorA.Allocate(Capacity * sizeof(T)));
        if (!DataPtr)
        {
            assert(false, "BadAllocation");        
        }
        *DataPtr = data;
        ++Size;
    }
    AVector(std::initializer_list<T> list) {}

    AVector(const AVector&) = delete;
    AVector& operator=(const AVector&) = delete;

    AVector(const AVector&&) {}
    AVector& operator=(const AVector&&) {}

    void Add(T data)
    {
        if (Size == Capacity)
        {
            Reserve(Capacity * 2);
        }
        auto ShifDataPtr = DataPtr + Size;
        *ShifDataPtr = data;
        ++Size;
    }

    void Reserve(size_t NewCapacity)
    {
        if (NewCapacity <= Capacity) return;

        T* Temp = static_cast<T*>(AllocatorA.Allocate(NewCapacity * sizeof(T)));
        for (size_t i = 0; i < Size; ++i)
        {
            auto ShiftTemp = Temp + i;
            *ShiftTemp = *(DataPtr + i);
        }
        AllocatorA.DeAllocate(DataPtr);
        DataPtr = Temp;
        Capacity = NewCapacity;
    }


    T& operator[](size_t index)
    {
        if (index >= Size)
        {
            assert(false, "Index out of range");
        }
        return DataPtr[index];
    }

    const T& operator[](size_t index) const
    {
        if (index >= Size)
        {
            assert(false, "Index out of range");
        }
        return DataPtr[index];
    }

private:
    T* DataPtr = nullptr;
    size_t Size = 0;
    size_t Capacity = 2;
    static constexpr size_t Alignment = 16;
    AlignedAllocator<Alignment> AllocatorA;
};