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
extern int i;
extern int l;
extern int lookbits;
extern int ctr;
extern unsigned int huffcode[257];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access via precomputed indices
    // Instead of repeatedly calculating lookbits and incrementing, we precompute the start index
    // and write to contiguous memory locations in a forward manner for better cache locality.

    int base_index = 0;
    for (l = 1; l <= 8; l++) {
        int shift = 8 - l;
        int count = 1 << shift;
        for (i = 1; i <= (int)htbl->bits[l]; i++, p++) {
            int start = (huffcode[p] << shift);
            base_index = start;
            UINT8 val = htbl->huffval[p];
            for (ctr = 0; ctr < count; ctr++) {
                dtbl->look_nbits[base_index + ctr] = l;
                dtbl->look_sym[base_index + ctr] = val;
            }
        }
    }
}
