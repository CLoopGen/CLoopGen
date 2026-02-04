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

typedef struct {
    unsigned int ehufco[256];
    char ehufsi[256];
} c_derived_tbl;

JHUFF_TBL *htbl;
c_derived_tbl *dtbl;
int p;
int lastp;
char huffsize[257];
unsigned int huffcode[257];

void init_vars() {
    htbl = (JHUFF_TBL*)malloc(sizeof(JHUFF_TBL));
    dtbl = (c_derived_tbl*)malloc(sizeof(c_derived_tbl));

    lastp = 256;

    for (int i = 0; i < 17; i++) {
        htbl->bits[i] = (UINT8)(i % 256);
    }
    for (int i = 0; i < 256; i++) {
        htbl->huffval[i] = (UINT8)i;
        dtbl->ehufco[i] = 0;
        dtbl->ehufsi[i] = 0;
        huffcode[i] = (unsigned int)(i * 1000);
        huffsize[i] = (char)(i % 128);
    }
    huffcode[256] = 0;
    huffsize[256] = 0;

    htbl->sent_table = 0;
}