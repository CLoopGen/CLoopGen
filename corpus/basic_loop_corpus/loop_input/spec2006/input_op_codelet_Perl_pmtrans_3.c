#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t STRLEN;
typedef unsigned char U8;
typedef int I32;

STRLEN tlen;
U8 *t;
I32 i;
short *tbl;

void init_vars() {
    tlen = 16777216; // 16MB to target ~0.01s runtime on modern CPU

    t = (U8*)malloc(tlen);
    if (!t) {
        fprintf(stderr, "Failed to allocate memory for t\n");
        exit(1);
    }

    for (STRLEN idx = 0; idx < tlen; idx++) {
        t[idx] = (U8)(idx % 256);
    }

    tbl = (short*)calloc(256, sizeof(short));
    if (!tbl) {
        fprintf(stderr, "Failed to allocate memory for tbl\n");
        exit(1);
    }

    for (int idx = 0; idx < 256; idx++) {
        tbl[idx] = (short)idx;
    }
}