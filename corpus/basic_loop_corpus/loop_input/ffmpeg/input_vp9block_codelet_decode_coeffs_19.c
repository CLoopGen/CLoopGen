#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint32_t u32;
    uint16_t u16[2];
    uint8_t u8[4];
    float f32;
} av_alias32;

int end_x;
int n;
uint8_t *a;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate
    a = (uint8_t*)aligned_alloc(32, data_size);
    if (!a) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        a[i] = (uint8_t)(i & 0xFF);
    }

    end_x = (int)(data_size - 8); // Ensure n+4 and n+8 are within bounds; loop steps by 4 and accesses [n] and [n+4]
    if (end_x < 0) end_x = 0;
}

__attribute__((destructor))
static void cleanup() {
    if (a) {
        free(a);
        a = NULL;
    }
}