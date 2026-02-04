#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int palette_scale = 2;
unsigned char r;
unsigned char g;
unsigned char b;
unsigned char palette_buffer[768];
uint32_t palette[256];

void init_vars() {
    palette_scale = 2;
    for (int idx = 0; idx < 768; ++idx) {
        palette_buffer[idx] = (unsigned char)(idx * 31 % 255);
    }
    for (int idx = 0; idx < 256; ++idx) {
        palette[idx] = 0;
    }
    i = 0;
}