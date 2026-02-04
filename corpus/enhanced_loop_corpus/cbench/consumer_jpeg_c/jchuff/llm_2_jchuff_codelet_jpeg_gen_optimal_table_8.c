#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

extern JHUFF_TBL *htbl;
extern int codesize[257];
extern int p;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with flattened indexing
    // Instead of iterating by code size then symbol, we precompute valid indices and traverse huffval consecutively
    int idx = 0;
    for (i = 0; i <= 256; i++) {
        if (codesize[i] > 0 && codesize[i] <= 32) {
            htbl->huffval[p + idx] = (UINT8)i;
            idx++;
        }
    }
    p += idx;
}
