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
    // Variant 2: Indirect array access using an index map to simulate non-linear traversal
    int index_map[16];
    // Create an indirect access pattern: reverse order with stride-like behavior
    for (int i = 0; i < 16; i++) {
        index_map[i] = 16 - i;  // reverse access: 16, 15, ..., 1
    }

    int temp_p = p;
    for (int i = 0; i < 16; i++) {
        int l = index_map[i];  // indirectly accessed loop variable

        if (htbl->bits[l]) {
            dtbl->valptr[l] = temp_p;
            dtbl->mincode[l] = huffcode[temp_p];
            temp_p += htbl->bits[l];
            dtbl->maxcode[l] = huffcode[temp_p - 1];
        } else {
            dtbl->maxcode[l] = -1;
        }
    }
    p = temp_p;  // update global p
}
