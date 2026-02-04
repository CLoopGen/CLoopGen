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
int val = 0x1234;

void init_vars() {
    size_t total_size = (size_t)(n_px_need) * 2;
    l = aligned_alloc(16, total_size);
    if (!l) {
        exit(1);
    }
    val = 0x1234;
    n_px_have = 0;
    n_px_need = 65536;
}