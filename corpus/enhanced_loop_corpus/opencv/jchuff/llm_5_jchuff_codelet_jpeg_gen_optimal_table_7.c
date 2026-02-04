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
    for (i = 0; i < num_nz_symbols - 1; ++i) {
        int current_code_size = codesize[i];
        int pos = bit_pos[current_code_size];
        htbl->huffval[pos] = (UINT8)nz_index[i];
        if (htbl->huffval[pos] != 0) {
            bit_pos[current_code_size] = pos + 1;
        }
    }
}
