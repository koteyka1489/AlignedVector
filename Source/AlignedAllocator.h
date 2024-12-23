#include <cstdlib>
#include <assert.h>



template <size_t Alignment>
class AlignedAllocator
{
public:
    static_assert((Alignment & (Alignment - 1)) == 0, "Alignment must be pow of 2");
    static_assert(Alignment > 0, "Alignment must be greater than 0"); 
    static_assert(Alignment <= 256, "Alignment too large");

    constexpr AlignedAllocator() noexcept = default; 

    [[nodiscard]] static inline void* Allocate(size_t Size) noexcept {
        return _aligned_malloc(Size, Alignment); }

    static inline void DeAllocate(void* Ptr) noexcept {
        _aligned_free(Ptr); }
};