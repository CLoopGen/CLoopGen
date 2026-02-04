#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int16_t *in;
int16_t *win;
int length;
int shift;

void init_vars() {
    length = 16777216; // ~32 MB of total data (3 arrays), ~16M elements * 2 bytes per int16_t
    shift = 4;

    in = (int16_t*)aligned_alloc(32, length * sizeof(int16_t));
    win = (int16_t*)aligned_alloc(32, length * sizeof(int16_t));
    out = (int16_t*)aligned_alloc(32, length * sizeof(int16_t));

    for (int i = 0; i < length; i++) {
        in[i] = rand() % 1024;
        win[i] = rand() % 1024;
        out[i] = 0;
    }
}