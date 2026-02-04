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
    int step = (lastp > 128) ? 3 : 1;
    for (p = 0; p < lastp; p += step) {
        int val = htbl->huffval[p];
        unsigned int code = huffcode[p];
        char size = huffsize[p];
        dtbl->ehufco[val] = code;
        dtbl->ehufsi[val] = size;
    }
}
