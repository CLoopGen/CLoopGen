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
    // Variant 1: Consecutive memory access pattern using local accumulators to reduce repeated struct dereferencing
    INT32 *mincode = dtbl->mincode;
    INT32 *maxcode = dtbl->maxcode;
    int *valptr = dtbl->valptr;
    const UINT8 *bits = htbl->bits;
    int current_p = p;

    for (l = 1; l <= 16; l++) {
        if (bits[l]) {
            valptr[l] = current_p;
            mincode[l] = huffcode[current_p];
            current_p += bits[l];
            maxcode[l] = huffcode[current_p - 1];
        } else {
            maxcode[l] = -1;
        }
    }

    p = current_p; // Update global p after loop
}
