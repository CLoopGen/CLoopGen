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
for (i = 0; i < num_nz_symbols - 1; i++) {
    htbl->huffval[bit_pos[codesize[i]]] = (UINT8)nz_index[i];
    bit_pos[codesize[i]]++;
}

}
