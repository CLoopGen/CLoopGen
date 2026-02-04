#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *dst;
float *src;
int dst_stridea;
int dst_strideb;
int src_stridea;
int src_strideb;
int add;
int i;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(float))
#define TOTAL_ELEMENTS (DATA_SIZE_MB * ELEMENTS_PER_MB)

static float static_dst[TOTAL_ELEMENTS];
static float static_src[TOTAL_ELEMENTS];

void init_vars() {
    const int N = 8;
    
    dst_stridea = 1;
    dst_strideb = 8;
    src_stridea = 1;
    src_strideb = 8;
    add = 1;
    i = 0;

    dst = static_dst;
    src = static_src;

    for (int idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        static_src[idx] = (float)(idx % N) * 0.5f;
        static_dst[idx] = (float)(idx % N) * 0.1f;
    }
}