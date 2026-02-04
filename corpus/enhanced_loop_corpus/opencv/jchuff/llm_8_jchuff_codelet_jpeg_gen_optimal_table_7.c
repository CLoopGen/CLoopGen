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
    int limit = num_nz_symbols - 1;
    for (i = 0; i < limit; i += 2) {
        int pos1 = codesize[i];
        int idx1 = bit_pos[pos1];
        htbl->huffval[idx1] = (UINT8)nz_index[i];
        bit_pos[pos1] = idx1 + 1;

        if (i + 1 < limit) {
            int pos2 = codesize[i + 1];
            int idx2 = bit_pos[pos2];
            htbl->huffval[idx2] = (UINT8)nz_index[i + 1];
            bit_pos[pos2] = idx2 + 1;
        }
    }
}
