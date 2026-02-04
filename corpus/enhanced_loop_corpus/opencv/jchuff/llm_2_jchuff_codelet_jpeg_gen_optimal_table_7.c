#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char UINT8;

typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

extern JHUFF_TBL *htbl;
extern int bit_pos[33];
extern int codesize[257];
extern int nz_index[257];
extern int i;
extern int num_nz_symbols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of sequential increment, access elements with a stride of 2 (unrolled-like pattern)
    // We simulate strided access by processing two iterations at once where possible
    int n = num_nz_symbols - 1;
    int limit = (n % 2 == 0) ? n : n - 1;
    for (i = 0; i < limit; i += 2) {
        htbl->huffval[bit_pos[codesize[i]]] = (UINT8)nz_index[i];
        bit_pos[codesize[i]]++;
        htbl->huffval[bit_pos[codesize[i + 1]]] = (UINT8)nz_index[i + 1];
        bit_pos[codesize[i + 1]]++;
    }
    // Handle remaining element if num_nz_symbols - 1 is odd
    if (limit < n) {
        htbl->huffval[bit_pos[codesize[limit]]] = (UINT8)nz_index[limit];
        bit_pos[codesize[limit]]++;
    }
}
