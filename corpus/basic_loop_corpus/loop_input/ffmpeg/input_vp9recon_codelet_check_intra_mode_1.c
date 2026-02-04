#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *a_data;
uint8_t **a;
int bpp;
int n_px_need;
int n;

void init_vars() {
    bpp = 16;
    n_px_need = 65536;
    a_data = (uint8_t*)aligned_alloc(16, n_px_need * 2);
    if (!a_data) exit(1);
    a = &a_data;
}

void loop();