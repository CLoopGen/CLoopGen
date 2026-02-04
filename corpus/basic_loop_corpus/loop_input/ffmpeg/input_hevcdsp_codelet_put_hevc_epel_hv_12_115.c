#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 256;
int width = 1024;
int x;
int y;
uint16_t *src;
ptrdiff_t srcstride = 1024;
int8_t *filter;
int16_t *tmp;

void init_vars() {
    filter = (int8_t*)malloc(4 * sizeof(int8_t));
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 0;

    src = (uint16_t*)calloc((height + 3) * srcstride + 4, sizeof(uint16_t));

    tmp = (int16_t*)calloc((width + 3) * 64, sizeof(int16_t));
}

extern void loop();

__attribute__((constructor))
static void constructor() {
    init_vars();
}