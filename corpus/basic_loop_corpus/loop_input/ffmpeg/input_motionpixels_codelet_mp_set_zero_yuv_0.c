#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct YuvPixel {
    int8_t y;
    int8_t v;
    int8_t u;
} YuvPixel;

YuvPixel *p;
int i;
int j;

static YuvPixel p_data[1 << 20]; // ~1MB of pixel data

void init_vars() {
    p = p_data;
    i = 0;
    j = 0;

    size_t size = sizeof(p_data) / sizeof(p_data[0]);
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&size));
    
    for (size_t idx = 0; idx < size; ++idx) {
        p[idx].y = rand() % 256 - 128;
        p[idx].v = rand() % 256 - 128;
        p[idx].u = rand() % 256 - 128;
    }

    for (int k = 0; k < 32; ++k) {
        if (k < 31) {
            p[k].y = 0;
            p[k].v = 0;
            p[k].u = 0;
        }
        p[size - 32 + k].y = 0;
        p[size - 32 + k].v = 0;
        p[size - 32 + k].u = 0;
    }
}