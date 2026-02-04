#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;
int E;
int step;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * 1024 * 1024 / sizeof(uint16_t))

static uint16_t internal_dst[TOTAL_ELEMENTS];
static uint16_t internal_src[TOTAL_ELEMENTS];

void init_vars() {
    const int min_h = 1000000; 
    const int max_h = 2000000; 

    A = 17;
    E = 23;
    step = 1;
    h = min_h + (rand() % (max_h - min_h + 1));
    stride = 1;

    while (h * stride >= TOTAL_ELEMENTS / 2) {
        stride++;
    }

    dst = internal_dst;
    src = internal_src;

    for (int idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        internal_dst[idx] = rand() & 0xFFFF;
        internal_src[idx] = rand() & 0xFFFF;
    }
}

__attribute__((constructor))
static void constructor_init() {
    srand((unsigned int)time(NULL));
    init_vars();
}