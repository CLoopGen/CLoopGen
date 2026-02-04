#include <stdio.h>

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

extern JHUFF_TBL *htbl;
extern c_derived_tbl *dtbl;
extern int p;
extern int lastp;
extern char huffsize[257];
extern unsigned int huffcode[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 2nd element in reverse order, then fill in gaps)
    int stride = 2;
    for (p = lastp - 1; p >= 0; p -= stride) {
        dtbl->ehufco[htbl->huffval[p]] = huffcode[p];
        dtbl->ehufsi[htbl->huffval[p]] = huffsize[p];
    }
    for (p = lastp - 2; p >= 0; p -= stride) {
        dtbl->ehufco[htbl->huffval[p]] = huffcode[p];
        dtbl->ehufsi[htbl->huffval[p]] = huffsize[p];
    }
}
