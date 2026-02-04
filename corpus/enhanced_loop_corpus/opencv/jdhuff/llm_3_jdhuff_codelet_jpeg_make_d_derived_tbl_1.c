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
    // Variant 2: Strided memory access with indirect addressing using pointer arithmetic
    // We change the inner loop to use strided writes by treating the arrays as if being accessed
    // with a fixed stride of 1 but through an offset pointer, simulating a different access pattern.
    // This variant also uses direct pointer increments to simulate streaming output.

    for (l = 1; l <= 8; l++) {
        int shift = 8 - l;
        int stride = 1;
        int entries = 1 << shift;
        for (i = 1; i <= (int)htbl->bits[l]; i++, p++) {
            int base = huffcode[p] << shift;
            int *nbits_ptr = &dtbl->look_nbits[base];
            UINT8 *sym_ptr = &dtbl->look_sym[base];
            UINT8 val = htbl->huffval[p];
            for (ctr = 0; ctr < entries; ctr += stride) {
                *(nbits_ptr + ctr) = l;
                *(sym_ptr + ctr) = val;
            }
        }
    }
}
