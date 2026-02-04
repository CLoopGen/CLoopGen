#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

typedef size_t STRLEN;
typedef unsigned char U8;
typedef int I32;

STRLEN tlen = 0;
STRLEN rlen = 0;
U8 *t = NULL;
U8 *r = NULL;
I32 i = 0;
I32 j = 0;
I32 del = 0;
I32 grows = 0;
short *tbl = NULL;

void init_vars() {
    const size_t input_size = 67108864; // ~64MB for ~0.01s runtime target

    tlen = input_size;
    rlen = input_size / 2;

    t = (U8*)malloc(tlen);
    r = (U8*)malloc(rlen);

    if (!t || !r) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < tlen; ++idx) {
        t[idx] = (U8)(idx % 256);
    }
    for (size_t idx = 0; idx < rlen; ++idx) {
        r[idx] = (U8)((idx + 33) % 256);
    }

    tbl = (short*)calloc(256, sizeof(short));
    if (!tbl) {
        fprintf(stderr, "Memory allocation for tbl failed\n");
        exit(1);
    }
    for (int idx = 0; idx < 256; ++idx) {
        tbl[idx] = -1;
    }

    del = 1;
    grows = 0;
    i = 0;
    j = 0;
}