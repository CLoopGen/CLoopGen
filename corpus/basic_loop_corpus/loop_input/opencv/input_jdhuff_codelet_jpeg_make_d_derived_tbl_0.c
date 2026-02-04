#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char UINT8;
typedef unsigned char boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

typedef long INT32;

typedef struct {
    INT32 maxcode[18];
    INT32 valoffset[17];
    JHUFF_TBL *pub;
    int look_nbits[256];
    UINT8 look_sym[256];
} d_derived_tbl;

JHUFF_TBL *htbl;
d_derived_tbl *dtbl;
int p;
int l;
unsigned int huffcode[257];

void init_vars() {
    htbl = (JHUFF_TBL*)calloc(1, sizeof(JHUFF_TBL));
    dtbl = (d_derived_tbl*)calloc(1, sizeof(d_derived_tbl));
    p = 0;

    for (int i = 0; i < 17; i++) {
        htbl->bits[i] = (i >= 1 && i <= 16) ? (16 - (i - 1)) : 0;
    }
    htbl->bits[0] = 0;

    for (int i = 0; i < 256; i++) {
        htbl->huffval[i] = i % 256;
    }
    htbl->sent_table = 0;

    for (int i = 0; i < 257; i++) {
        huffcode[i] = (1U << (i % 24)) + (i * 17);
    }

    dtbl->pub = htbl;
    for (int i = 0; i < 256; i++) {
        dtbl->look_nbits[i] = i % 16;
        dtbl->look_sym[i] = i % 256;
    }
}