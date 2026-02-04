#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int size;
int x;
int y;
uint16_t *src;
int angle;
uint16_t *ref;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

static uint16_t internal_src[TOTAL_ELEMENTS];
static uint16_t internal_ref[TOTAL_ELEMENTS];

void init_vars() {
    size = 512;
    stride = size;
    angle = 37; 
    src = internal_src;
    ref = internal_ref;

    memset(src, 0, TOTAL_ELEMENTS * sizeof(uint16_t));
    for (int i = 0; i < TOTAL_ELEMENTS; i++) {
        ref[i] = rand() & 0xFFFF;
    }
}