#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

int end_x;
int n;
uint8_t *a;

void init_vars() {
    const size_t data_size = 128 << 20; // 128 MB
    a = aligned_alloc(32, data_size);
    if (!a) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        a[i] = rand() % 256;
    }

    end_x = data_size - (data_size % 2) - 2; // Ensure n+2 doesn't go out of bounds
}