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
int length;
int i;

void init_vars() {
    htbl = (JHUFF_TBL*)calloc(1, sizeof(JHUFF_TBL));
    if (!htbl) {
        exit(1);
    }
    length = 0;
    i = 0;
    for (int j = 1; j <= 16; j++) {
        htbl->bits[j] = 1;
    }
}