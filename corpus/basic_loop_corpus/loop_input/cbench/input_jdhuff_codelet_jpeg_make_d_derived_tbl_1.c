#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char UINT8;
typedef int boolean;
typedef long INT32;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

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
int l;
unsigned int huffcode[257];

void init_vars() {
    htbl = (JHUFF_TBL *)malloc(sizeof(JHUFF_TBL));
    dtbl = (d_derived_tbl *)malloc(sizeof(d_derived_tbl));

    memset(htbl->bits, 0, sizeof(htbl->bits));
    memset(htbl->huffval, 0, sizeof(htbl->huffval));
    htbl->sent_table = 0;

    for (int i = 1; i <= 16; i++) {
        htbl->bits[i] = 15; // Ensures non-zero for several levels to trigger the if branch
    }
    htbl->bits[0] = 0;

    p = 0;
    for (int i = 0; i < 257; i++) {
        huffcode[i] = (unsigned int)(i * 100 + (i % 17)); 
    }

    dtbl->pub = htbl;
    memset(dtbl->mincode, 0, sizeof(dtbl->mincode));
    memset(dtbl->maxcode, 0, sizeof(dtbl->maxcode));
    memset(dtbl->valptr, 0, sizeof(dtbl->valptr));
    memset(dtbl->look_nbits, 0, sizeof(dtbl->look_nbits));
    memset(dtbl->look_sym, 0, sizeof(dtbl->look_sym));
}