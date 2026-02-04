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

int i;
uint16_t *src;
int stride;
uint64_t a;
uint64_t b;

static uint16_t *internal_src_buffer;

void init_vars() {
    // Set data size to ~64MB of source data to target ~0.01s runtime on modern CPU
    const size_t total_size = 64 * 1024 * 1024; // 64 MB
    const size_t element_size = sizeof(uint16_t);
    const size_t num_elements = total_size / element_size;

    // Allocate buffer with padding to ensure no out-of-bounds access
    // Loop accesses up to i=15, each access uses 2 uint64_t = 4 uint16_t elements per pointer
    // So we need at least 16 * stride + 4 elements safely accessible
    // Choose stride conservatively as at least 256 bytes (128 uint16_t) to simulate realistic access pattern
    stride = 128; // in units of uint16_t

    // Ensure buffer is large enough: 16 iterations * stride + 4 extra uint64_t-aligned elements
    size_t required_elements = 16 * stride + 4;
    if (num_elements < required_elements) {
        internal_src_buffer = aligned_alloc(64, required_elements * sizeof(uint16_t));
    } else {
        internal_src_buffer = aligned_alloc(64, num_elements * sizeof(uint16_t));
    }

    if (!internal_src_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    src = internal_src_buffer;

    // Initialize a and b with non-zero test values
    a = 0xdeadbeefcafe1234ULL;
    b = 0xc0defeedface5678ULL;

    // Optionally initialize some source memory for consistency
    for (size_t idx = 0; idx < required_elements; idx++) {
        src[idx] = (uint16_t)(idx & 0xFFFF);
    }
}