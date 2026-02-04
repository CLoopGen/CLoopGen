#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int palette_scale;
unsigned char palette_buffer[768];

void init_vars() {
    for (int idx = 0; idx < 768; idx++) {
        palette_buffer[idx] = (unsigned char)(idx % 64); // ensures no value > 63
    }
    palette_scale = 1;
    i = 0;
}