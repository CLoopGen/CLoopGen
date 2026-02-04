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
    // Variant 1: Consecutive memory access using pointer arithmetic to traverse htbl->bits and dtbl arrays
    INT32 *valoffset_ptr = dtbl->valoffset + 1;
    INT32 *maxcode_ptr = dtbl->maxcode + 1;
    UINT8 *bits_ptr = htbl->bits + 1;
    int l_local = 1;

    for (; l_local <= 16; l_local++) {
        if (*bits_ptr) {
            *valoffset_ptr = (INT32)p - (INT32)huffcode[p];
            p += *bits_ptr;
            *maxcode_ptr = huffcode[p - 1];
        } else {
            *maxcode_ptr = -1;
        }
        // Move pointers forward
        valoffset_ptr++;
        maxcode_ptr++;
        bits_ptr++;
    }
}
