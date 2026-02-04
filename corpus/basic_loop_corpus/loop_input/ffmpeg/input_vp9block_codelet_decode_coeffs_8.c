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

int end_x;
int n;
uint8_t *a;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    a = aligned_alloc(8, data_size);
    if (!a) {
        exit(1);
    }
    end_x = data_size - (data_size % 8); // Ensure multiple of 8 to avoid overflow in loop (n += 2, access 8 bytes)
}