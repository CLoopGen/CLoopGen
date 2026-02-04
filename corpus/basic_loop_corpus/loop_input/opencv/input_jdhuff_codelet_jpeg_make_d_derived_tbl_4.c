#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char UINT8;
typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

typedef long JLONG;

typedef struct {
    JLONG maxcode[18];
    JLONG valoffset[18];
    JHUFF_TBL *pub;
    int lookup[256];
} d_derived_tbl;

JHUFF_TBL *htbl;
d_derived_tbl *dtbl;
int p;
int i;
int l;
int lookbits;
int ctr;
unsigned int huffcode[257];

void init_vars() {
    htbl = (JHUFF_TBL*)calloc(1, sizeof(JHUFF_TBL));
    dtbl = (d_derived_tbl*)calloc(1, sizeof(d_derived_tbl));

    if (!htbl || !dtbl) {
        exit(1);
    }

    htbl->sent_table = 0;

    for (int idx = 0; idx < 17; idx++) {
        htbl->bits[idx] = 0;
    }

    htbl->bits[1] = 4;
    htbl->bits[2] = 5;
    htbl->bits[3] = 6;
    htbl->bits[4] = 7;
    htbl->bits[5] = 8;
    htbl->bits[6] = 9;
    htbl->bits[7] = 10;
    htbl->bits[8] = 11;

    for (int idx = 0; idx < 256; idx++) {
        htbl->huffval[idx] = idx % 256;
    }

    for (int idx = 0; idx < 257; idx++) {
        huffcode[idx] = idx * 17 + 1;
    }

    p = 0;

    dtbl->pub = htbl;

    for (int idx = 0; idx < 18; idx++) {
        dtbl->maxcode[idx] = -1;
        dtbl->valoffset[idx] = 0;
    }
}