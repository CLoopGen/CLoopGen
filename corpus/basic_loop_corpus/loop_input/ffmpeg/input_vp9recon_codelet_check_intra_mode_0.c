#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

static uint8_t *data_buffer;
uint8_t **a;
int n_px_need = 65536;
int n_px_have = 0;
int n;
int val = 0x4242;

void init_vars() {
    size_t total_size = n_px_need * 2;
    data_buffer = (uint8_t*)aligned_alloc(16, total_size);
    if (!data_buffer) {
        exit(1);
    }
    a = (uint8_t**)malloc(sizeof(uint8_t*));
    if (!a) {
        exit(1);
    }
    a[0] = data_buffer;
    val = 0x4242;
    n_px_have = 0;
    n_px_need = 65536;
    n = 0;
}