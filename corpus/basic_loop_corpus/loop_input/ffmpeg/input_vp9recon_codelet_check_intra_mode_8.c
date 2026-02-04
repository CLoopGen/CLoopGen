#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *l;
int n_px_need = 65536;
int n_px_have = 0;
int n;
int val = 0x4242;

void init_vars() {
    size_t data_size = 131072; // 256KB of data (each element is 2 bytes)
    l = aligned_alloc(16, data_size);
    if (!l) {
        exit(1);
    }
    val = 0x4242;
    n_px_need = 65536;
    n_px_have = 0;
    n = 0;
}