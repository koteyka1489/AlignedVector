#include "AlignedAllocator.h"
#include <initializer_list>


template <typename T, size_t Alignment = 16>
class AVector
{
public:
    AVector() = default;
    AVector(T data) {

    }
    AVector(std::initializer_list<T> list) {

    }

    AVector(const AVector&) = delete;
    AVector& operator=(const AVector&) = delete;

    AVector(const AVector&&) {

    }
    AVector& operator=(const AVector&&) {

    }


private:
    T* Data = nullptr;
    size_t Size = 0;
    size_t Capacity = 0;
};