#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *t;
int pitch;
int16_t *ps;
int y;
int x;

void init_vars() {
    pitch = 512;
    int t_size = 4 * pitch * 2 + 16;
    t = (uint8_t*)aligned_alloc(32, t_size);
    ps = (int16_t*)aligned_alloc(32, 4 * 16 * sizeof(int16_t));

    for (int i = 0; i < t_size; i++) {
        t[i] = i & 0xFF;
    }
    for (int i = 0; i < 4 * 16; i++) {
        ps[i] = 0;
    }
}