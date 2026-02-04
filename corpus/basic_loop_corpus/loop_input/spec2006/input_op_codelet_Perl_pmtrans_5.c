#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef size_t STRLEN;
typedef unsigned char U8;
typedef int I32;

STRLEN rlen;
U8 *r;
I32 i;
I32 j;
short *tbl;

void init_vars() {
    rlen = 131072; // 128KB of data to target ~0.01 sec runtime
    j = 0;
    
    r = (U8*)malloc(rlen * sizeof(U8));
    tbl = (short*)malloc((257 + rlen - j) * sizeof(short));
    
    if (!r || !tbl) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (STRLEN idx = 0; idx < rlen; idx++) {
        r[idx] = (U8)(idx & 0xFF);
    }

    for (STRLEN idx = 0; idx < 257 + rlen - j; idx++) {
        tbl[idx] = 0;
    }
}