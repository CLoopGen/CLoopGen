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
    // Variant 2: Reduced computational complexity with merged outer loops and reduced trip count
    // Combine small l values into a single pass with conditional handling
    for (l = 1; l <= 4; l++) {  // Reduced outer loop bound
        int step = (int)htbl->bits[l];
        for (i = 0; i < step; i++, p++) {
            int base_bits = huffcode[p] << (8 - l);
            int range = 1 << (8 - l);

            // Simplified single assignment without nested loop via direct iteration
            for (ctr = 0; ctr < range; ctr++) {
                int idx = base_bits + ctr;
                // Add lightweight arithmetic transformation to maintain realism
                dtbl->look_nbits[idx] = l + (idx & 0x01);  // Slight variation in stored value
                dtbl->look_sym[idx] = htbl->huffval[p] ^ ((idx >> 2) & 0x03);
            }
        }
    }

    // Final pass for l = 5 only, skipping higher levels to reduce work
    l = 5;
    if (htbl->bits[l] > 0) {
        for (i = 1; i <= (int)htbl->bits[l]; i++, p++) {
            lookbits = huffcode[p] << (8 - l);
            for (ctr = 1 << (8 - l); ctr > 0; ctr--, lookbits++) {
                dtbl->look_nbits[lookbits] = l;
                dtbl->look_sym[lookbits] = htbl->huffval[p];
            }
        }
    }
}
