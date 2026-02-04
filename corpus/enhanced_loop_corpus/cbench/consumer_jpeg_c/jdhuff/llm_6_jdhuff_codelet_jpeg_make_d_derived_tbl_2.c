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
    int l, i, ctr;
    unsigned int huffcode_local[257];
    
    // Create local copy to eliminate potential WAW and WAR hazards with external huffcode
    for (int idx = 0; idx <= 256; idx++) {
        huffcode_local[idx] = huffcode[idx];
    }

    p = 0; // Reset p since it's used as an external counter

    for (l = 1; l <= 8; l++) {
        int bits_l = htbl->bits[l]; // Load once to remove repeated memory access (eliminate RAW per iteration)
        for (i = 1; i <= bits_l; i++) {
            int lookbits_base = huffcode_local[p] << (8 - l);
            int nbits_val = l;
            UINT8 sym_val = htbl->huffval[p];
            int shift = 8 - l;
            int count = 1 << shift;

            // Unrolled-like pattern with independent computation to reduce loop-carried dependency
            for (ctr = 0; ctr < count; ctr++) {
                int index = lookbits_base + ctr;
                dtbl->look_nbits[index] = nbits_val;
                dtbl->look_sym[index] = sym_val;
            }
            p++;
        }
    }
}
