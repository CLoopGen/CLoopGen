#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
int i;
int l;
int lookbits;
int ctr;
unsigned int huffcode[257];

void init_vars() {
    htbl = (JHUFF_TBL*)calloc(1, sizeof(JHUFF_TBL));
    dtbl = (d_derived_tbl*)calloc(1, sizeof(d_derived_tbl));

    htbl->sent_table = 0;

    for (int idx = 0; idx < 17; idx++) {
        htbl->bits[idx] = 0;
    }

    for (int idx = 0; idx < 256; idx++) {
        htbl->huffval[idx] = idx & 0xFF;
    }

    htbl->bits[1] = 2;
    htbl->bits[2] = 3;
    htbl->bits[3] = 4;
    htbl->bits[4] = 5;
    htbl->bits[5] = 6;
    htbl->bits[6] = 7;
    htbl->bits[7] = 8;
    htbl->bits[8] = 9;

    for (int idx = 0; idx < 257; idx++) {
        huffcode[idx] = idx * 17 + 1;
    }

    p = 0;

    memset(dtbl->look_nbits, 0, sizeof(dtbl->look_nbits));
    memset(dtbl->look_sym, 0, sizeof(dtbl->look_sym));
}