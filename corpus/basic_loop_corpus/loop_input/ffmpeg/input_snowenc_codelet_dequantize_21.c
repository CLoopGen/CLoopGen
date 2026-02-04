#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;

IDWTELEM *src;
int stride;
int w;
int h;
int qmul;
int qadd;
int x;
int y;

void init_vars() {
    w = 4096;
    h = 4096;
    stride = w;
    qmul = 3;
    qadd = 2;

    src = (IDWTELEM*)aligned_alloc(32, w * h * sizeof(IDWTELEM));
    if (!src) exit(1);

    for (int i = 0; i < w * h; i++) {
        src[i] = (rand() % 201) - 100;
    }
}