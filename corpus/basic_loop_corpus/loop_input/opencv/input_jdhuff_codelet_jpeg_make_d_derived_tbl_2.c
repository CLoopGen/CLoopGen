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
int l;
unsigned int huffcode[257];

void init_vars() {
    htbl = (JHUFF_TBL*)calloc(1, sizeof(JHUFF_TBL));
    dtbl = (d_derived_tbl*)calloc(1, sizeof(d_derived_tbl));
    p = 1;

    for (int i = 0; i < 17; i++) {
        htbl->bits[i] = (i >= 1 && i <= 16) ? (UINT8)(10 + (i % 7)) : 0;
    }
    htbl->bits[0] = 0;

    for (int i = 0; i < 256; i++) {
        htbl->huffval[i] = i % 255;
    }
    htbl->sent_table = 0;

    dtbl->pub = htbl;
    for (int i = 0; i < 256; i++) {
        dtbl->lookup[i] = i * 2;
    }

    for (int i = 0; i < 257; i++) {
        huffcode[i] = (i + 1) * 1000;
    }

    for (int i = 0; i < 18; i++) {
        dtbl->maxcode[i] = -1;
        dtbl->valoffset[i] = 0;
    }
}