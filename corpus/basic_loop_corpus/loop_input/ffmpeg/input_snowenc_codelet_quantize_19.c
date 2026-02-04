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
int qmul;
int x;
int y;
int thres1;
int thres2;
IDWTELEM *dst;

void init_vars() {
    w = 4096;
    h = 4096;
    stride = w;
    thres1 = 100;
    thres2 = 200;
    qmul = 37;

    src = (DWTELEM*)aligned_alloc(32, w * h * sizeof(DWTELEM));
    dst = (IDWTELEM*)aligned_alloc(32, w * h * sizeof(IDWTELEM));

    for (int i = 0; i < w * h; i++) {
        src[i] = rand() % 500 - 250;
    }
}