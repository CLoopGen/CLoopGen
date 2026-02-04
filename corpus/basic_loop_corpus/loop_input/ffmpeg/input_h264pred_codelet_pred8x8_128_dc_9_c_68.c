#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint64_t u64;
    uint32_t u32[2];
    uint16_t u16[4];
    uint8_t u8[8];
    double f64;
    float f32[2];
} av_alias64;

ptrdiff_t stride;
int i;
uint64_t a;
uint16_t *src;

void init_vars() {
    // Allocate approximately 128MB of data to achieve ~0.01s runtime on modern CPUs
    const size_t total_size = 128 * 1024 * 1024; // 128 MB
    const size_t num_uint16 = total_size / sizeof(uint16_t);
    
    // Ensure src can accommodate at least 8 iterations with stride offset and 2 uint64_t (4 uint16_t) accesses
    // Each iteration accesses (src + i * stride) and adds up to 2 uint64_t = 4 uint16_t
    // So we need: 8 * stride + 4 <= num_uint16
    // Choose stride large enough to avoid overlap, e.g., 16384 uint16_t apart (~32KB)
    stride = 16384;
    
    // Make sure total buffer is big enough: 8*stride + 4 elements
    if (8 * stride + 4 > num_uint16) {
        // Adjust total size to fit required access
        size_t min_size = (8 * stride + 4) * sizeof(uint16_t);
        src = aligned_alloc(64, min_size);
    } else {
        src = aligned_alloc(64, total_size);
    }

    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize a with non-zero value for realistic use
    a = 0xCAFEBABEDEADBEEFULL;

    // Optionally initialize part of src to avoid undefined behavior if read
    for (size_t idx = 0; idx < 8 * stride + 4; idx++) {
        src[idx] = (uint16_t)(idx ^ 0xABCD);
    }
}