#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    htbl = (JHUFF_TBL*)malloc(sizeof(JHUFF_TBL));
    if (!htbl) return;

    memset(htbl->bits, 0, sizeof(htbl->bits));
    memset(htbl->huffval, 0, sizeof(htbl->huffval));
    htbl->sent_table = 0;

    for (int idx = 1; idx <= 16; idx++) {
        htbl->bits[idx] = 16; 
    }

    p = 0;
    memset(huffsize, 0, sizeof(huffsize));
}