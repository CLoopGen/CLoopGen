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

extern JHUFF_TBL *htbl;
extern d_derived_tbl *dtbl;
extern int p;
extern int l;
extern unsigned int huffcode[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 local_p = p;
    for (l = 1; l <= 16; l++) {
        if (htbl->bits[l]) {
            dtbl->valoffset[l] = (INT32)local_p - (INT32)huffcode[local_p];
            dtbl->maxcode[l] = huffcode[local_p + htbl->bits[l] - 1];
            local_p += htbl->bits[l];
        } else {
            dtbl->maxcode[l] = -1;
        }
    }
    p = local_p;
}
