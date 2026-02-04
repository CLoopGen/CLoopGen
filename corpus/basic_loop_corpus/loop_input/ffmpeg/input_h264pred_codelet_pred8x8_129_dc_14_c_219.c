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

#define DATA_SIZE (128 << 20) // 128 MB

void init_vars() {
    // Initialize scalar variables
    stride = 16; // ensures alignment and safe access
    a = 0xdeadbeefdeadbeefULL;

    // Allocate large buffer to achieve desired runtime
    src = aligned_alloc(64, DATA_SIZE);
    if (!src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Ensure memory is writable and initialize some values
    for (size_t j = 0; j < DATA_SIZE / sizeof(uint16_t); j++) {
        src[j] = j & 0xFFFF;
    }
}