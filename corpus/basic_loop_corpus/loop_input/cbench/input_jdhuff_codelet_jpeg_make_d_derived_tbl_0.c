#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char UINT8;
typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

JHUFF_TBL *htbl;
int p;
int i;
int l;
char huffsize[257];

void init_vars() {
    htbl = (JHUFF_TBL*)calloc(1, sizeof(JHUFF_TBL));
    if (!htbl) return;

    p = 0;

    for (int len = 1; len <= 16; len++) {
        htbl->bits[len] = 16; 
    }

    const int total_entries = 16 * 16; 
    if (total_entries >= 257) {
        htbl->bits[16] -= (total_entries - 256);
    }
}