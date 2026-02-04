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
    for (l = 1; l <= 16; l += 2) {
        int has_bit_current = htbl->bits[l];
        int has_bit_next = (l + 1 <= 16) ? htbl->bits[l + 1] : 0;

        if (has_bit_current) {
            dtbl->valoffset[l] = (INT32)p - (INT32)huffcode[p];
            p += htbl->bits[l];
            dtbl->maxcode[l] = huffcode[p - 1];
        } else {
            dtbl->maxcode[l] = -1;
        }

        if (l + 1 <= 16) {
            if (has_bit_next) {
                dtbl->valoffset[l + 1] = (INT32)p - (INT32)huffcode[p];
                p += htbl->bits[l + 1];
                dtbl->maxcode[l + 1] = huffcode[p - 1];
            } else {
                dtbl->maxcode[l + 1] = -1;
            }
        }
    }
}
