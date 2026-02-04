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

typedef long JLONG;

typedef struct {
    JLONG maxcode[18];
    JLONG valoffset[18];
    JHUFF_TBL *pub;
    int lookup[256];
} d_derived_tbl;

extern JHUFF_TBL *htbl;
extern d_derived_tbl *dtbl;
extern int p;
extern int i;
extern int l;
extern int lookbits;
extern int ctr;
extern unsigned int huffcode[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = 1; l <= 8; l++) {
        for (i = 1; i <= (int)htbl->bits[l]; i++, p++) {
            lookbits = huffcode[p] << (8 - l);
            dtbl->lookup[lookbits] = (l << 8) | htbl->huffval[p];
        }
    }
}
