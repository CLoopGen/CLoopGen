#include <stdio.h>

#include <inttypes.h>

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

extern JHUFF_TBL *htbl;
extern d_derived_tbl *dtbl;
extern int p;
extern int l;
extern unsigned int huffcode[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 1; l <= 8; l++) {
        if (htbl->bits[l]) {
            dtbl->valptr[l] = p;
            dtbl->mincode[l] = huffcode[p] >> 1;
            p += htbl->bits[l];
            dtbl->maxcode[l] = (huffcode[p - 1] << 1) | 1;
        } else {
            dtbl->maxcode[l] = -1;
        }
        int inv_l = 17 - l;
        if (htbl->bits[inv_l]) {
            dtbl->valptr[inv_l] = p;
            dtbl->mincode[inv_l] = huffcode[p] + 1;
            p += htbl->bits[inv_l];
            dtbl->maxcode[inv_l] = huffcode[p - 1] - 1;
        } else {
            dtbl->maxcode[inv_l] = -1;
        }
    }
}
