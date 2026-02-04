#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char UINT8;
typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

typedef long INT32;

typedef struct {
    INT32 mincode[17];
    INT32 maxcode[18];
    int valptr[17];
    JHUFF_TBL *pub;
    int look_nbits[256];
    UINT8 look_sym[256];
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
    htbl = (JHUFF_TBL*)malloc(sizeof(JHUFF_TBL));
    dtbl = (d_derived_tbl*)malloc(sizeof(d_derived_tbl));

    memset(htbl->bits, 0, sizeof(htbl->bits));
    memset(htbl->huffval, 0, sizeof(htbl->huffval));
    htbl->sent_table = 0;

    for (int idx = 0; idx < 17; idx++) {
        dtbl->mincode[idx] = 0;
        dtbl->valptr[idx] = 0;
    }
    for (int idx = 0; idx < 18; idx++) {
        dtbl->maxcode[idx] = 0;
    }

    dtbl->pub = htbl;

    for (int idx = 0; idx < 256; idx++) {
        dtbl->look_nbits[idx] = 0;
        dtbl->look_sym[idx] = 0;
    }

    for (int idx = 0; idx < 257; idx++) {
        huffcode[idx] = (unsigned int)(idx * 17 + 13);
    }

    htbl->bits[1] = 5;
    htbl->bits[2] = 4;
    htbl->bits[3] = 3;
    htbl->bits[4] = 3;
    htbl->bits[5] = 2;
    htbl->bits[6] = 2;
    htbl->bits[7] = 1;
    htbl->bits[8] = 1;

    for (int idx = 1; idx <= 16; idx++) {
        if (idx <= 8) {
            htbl->bits[idx] = (htbl->bits[idx] > 0) ? htbl->bits[idx] : 0;
        } else {
            htbl->bits[idx] = 0;
        }
    }

    for (int idx = 0; idx < 256; idx++) {
        htbl->huffval[idx] = (UINT8)(idx % 255);
    }

    p = 0;
}