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

JHUFF_TBL *htbl;
int bit_pos[33];
int codesize[257];
int nz_index[257];
int i;
int num_nz_symbols;

void init_vars() {
    htbl = (JHUFF_TBL*)calloc(1, sizeof(JHUFF_TBL));
    if (!htbl) exit(1);

    for (int idx = 0; idx < 17; idx++) {
        htbl->bits[idx] = (UINT8)(idx % 256);
    }
    htbl->sent_table = 0;

    for (int idx = 0; idx < 256; idx++) {
        htbl->huffval[idx] = 0;
    }

    for (int idx = 0; idx < 33; idx++) {
        bit_pos[idx] = idx < 17 ? 0 : idx - 17;
    }

    for (int idx = 0; idx < 257; idx++) {
        codesize[idx] = idx % 33;
        nz_index[idx] = idx % 256;
    }

    num_nz_symbols = 256;
}