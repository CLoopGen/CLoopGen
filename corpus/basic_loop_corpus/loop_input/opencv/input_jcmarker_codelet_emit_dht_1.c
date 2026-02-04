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
int length;
int i;

void init_vars() {
    htbl = (JHUFF_TBL *)calloc(1, sizeof(JHUFF_TBL));
    if (!htbl) exit(1);

    for (int j = 0; j < 17; j++) {
        htbl->bits[j] = (UINT8)(j * 7 % 251);
    }

    for (int j = 0; j < 256; j++) {
        htbl->huffval[j] = (UINT8)(j * 13 % 199);
    }

    htbl->sent_table = 0;
    length = 0;
    i = 0;
}