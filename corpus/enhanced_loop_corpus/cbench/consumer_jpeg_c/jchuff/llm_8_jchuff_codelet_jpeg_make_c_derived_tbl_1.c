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
    int i;
    for (p = 0; p < lastp; p += 2) {
        if (p + 1 < lastp) {
            dtbl->ehufco[htbl->huffval[p]] = huffcode[p];
            dtbl->ehufsi[htbl->huffval[p]] = huffsize[p];
            dtbl->ehufco[htbl->huffval[p+1]] = huffcode[p+1];
            dtbl->ehufsi[htbl->huffval[p+1]] = huffsize[p+1];
        } else {
            dtbl->ehufco[htbl->huffval[p]] = huffcode[p];
            dtbl->ehufsi[htbl->huffval[p]] = huffsize[p];
        }
    }
}
