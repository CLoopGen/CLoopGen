#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t j;
unsigned char *colormap;
unsigned char *global_colormap;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data

    colormap = (unsigned char*)malloc(data_size);
    global_colormap = (unsigned char*)malloc(data_size);

    if (!colormap || !global_colormap) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        colormap[i] = (unsigned char)(i & 0xFF);
    }
}