#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef size_t STRLEN;
typedef unsigned char U8;
typedef int I32;

STRLEN rlen = 1 << 20; // 1MB of data to target ~0.01 sec runtime
U8 *r = NULL;
I32 i = 0;
I32 j = 0;
I32 del = 0;
I32 grows = 0;
short *tbl = NULL;

void init_vars() {
    r = (U8*)malloc(rlen);
    tbl = (short*)calloc(256, sizeof(short));

    if (!r || !tbl) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (STRLEN k = 0; k < rlen; ++k) {
        r[k] = (U8)(k % 256);
    }

    for (int idx = 0; idx < 256; ++idx) {
        tbl[idx] = 0;
    }

    i = 0;
    j = 0;
    del = 0;
    grows = 0;
}