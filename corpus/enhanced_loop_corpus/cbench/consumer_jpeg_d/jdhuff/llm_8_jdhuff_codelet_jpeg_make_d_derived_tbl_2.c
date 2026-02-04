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
extern int i;
extern int l;
extern int lookbits;
extern int ctr;
extern unsigned int huffcode[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling inner loop and increasing arithmetic operations
    for (l = 1; l <= 8; l++) {
        int bits_l = (int)htbl->bits[l];
        for (i = 1; i <= bits_l; i++, p++) {
            lookbits = huffcode[p] << (8 - l);
            int shift_val = 8 - l;
            int loop_count = 1 << shift_val;
            int end = lookbits + loop_count;

            // Unroll by 4x where possible to increase arithmetic and memory operations
            for (; lookbits + 3 < end; lookbits += 4) {
                dtbl->look_nbits[lookbits]     = l;
                dtbl->look_sym[lookbits]       = htbl->huffval[p];
                dtbl->look_nbits[lookbits + 1] = l;
                dtbl->look_sym[lookbits + 1]   = htbl->huffval[p];
                dtbl->look_nbits[lookbits + 2] = l;
                dtbl->look_sym[lookbits + 2]   = htbl->huffval[p];
                dtbl->look_nbits[lookbits + 3] = l;
                dtbl->look_sym[lookbits + 3]   = htbl->huffval[p];
            }
            // Handle remaining elements
            while (lookbits < end) {
                dtbl->look_nbits[lookbits] = l;
                dtbl->look_sym[lookbits] = htbl->huffval[p];
                lookbits++;
            }
        }
    }
}
