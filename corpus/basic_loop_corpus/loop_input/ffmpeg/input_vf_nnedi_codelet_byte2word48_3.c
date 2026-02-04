#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *t;
int pitch;
int16_t *p;
int y;
int x;

void init_vars() {
    pitch = 512;
    int t_size = 4 * pitch * 2 * sizeof(uint8_t);
    t = aligned_alloc(32, t_size);
    p = aligned_alloc(32, 4 * 12 * sizeof(int16_t));

    for (int i = 0; i < t_size; i++) {
        t[i] = rand() % 256;
    }
    for (int i = 0; i < 4 * 12; i++) {
        p[i] = 0;
    }
}