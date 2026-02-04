#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with reversed traversal order (backward striding)
    // Instead of forward sequential access, this variant accesses elements from the end
    // using negative strides, changing spatial access pattern which may affect cache behavior.

    int i;
    uint8_t *dst_start = dst;
    uint8_t *src_start = src;

    // Compute starting pointers for reverse access
    dst += (h - 1) * dstStride;
    src += (h - 1) * srcStride;

    for (i = 0; i < h; i++) {
        ((((union unaligned_32 *)(dst))->l) = ((((const union unaligned_32 *)(src))->l)));
        dst -= dstStride;
        src -= srcStride;
    }

    // Restore original pointers if needed (not strictly necessary unless used later)
    // Here we assume no side effects beyond the loop.
}
