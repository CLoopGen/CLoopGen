#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DWTELEM;
typedef short IDWTELEM;

DWTELEM *src;
int stride;
int w;
int h;
int x;
int y;
IDWTELEM *dst;

void init_vars() {
    w = 4096;
    h = 4096;
    stride = w;

    src = (DWTELEM*)aligned_alloc(32, w * h * sizeof(DWTELEM));
    dst = (IDWTELEM*)aligned_alloc(32, w * h * sizeof(IDWTELEM));

    for (int i = 0; i < w * h; i++) {
        src[i] = rand() % 65536 - 32768;
        dst[i] = 0;
    }
}