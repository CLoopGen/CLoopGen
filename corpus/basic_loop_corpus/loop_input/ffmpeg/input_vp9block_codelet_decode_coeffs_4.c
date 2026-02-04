#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

int end_y;
int n;
uint8_t *l;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB
    l = (uint8_t *)aligned_alloc(__alignof__(av_alias16), data_size);
    end_y = data_size - (data_size % 2); // Ensure it's even to avoid out-of-bounds access

    for (size_t i = 0; i < data_size; i++) {
        l[i] = rand() % 256;
    }
}