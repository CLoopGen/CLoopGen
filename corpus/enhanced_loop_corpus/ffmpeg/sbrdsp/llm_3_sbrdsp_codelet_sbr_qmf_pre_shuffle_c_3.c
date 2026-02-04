#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union av_intfloat32 {
    uint32_t i;
    float f;
};


extern union av_intfloat32 *zi;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Access with Fixed Stride (Improved Cache Behavior via Stride Unrolling)
    // Instead of variable base indexing, use a fixed increment pattern that enables better
    // prefetching and vectorization due to predictable stride.
    int base_offset = 64;
    int stride = 4; // Fixed stride across iterations
    for (k = 1; k < 31; k += 2) {
        int write_idx = base_offset + ((k - 1) / 2) * stride;
        zi[write_idx + 0].i = zi[64 - k].i ^ (1U << 31);
        zi[write_idx + 1].i = zi[k + 1].i;
        zi[write_idx + 2].i = zi[63 - k].i ^ (1U << 31);
        zi[write_idx + 3].i = zi[k + 2].i;
    }
}
