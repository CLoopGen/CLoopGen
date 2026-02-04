#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UINT8;

typedef int boolean;

typedef struct {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL;

typedef long INT32;

typedef struct {
    INT32 mincode[17];
    INT32 maxcode[18];
    int valptr[17];
    JHUFF_TBL *pub;
    int look_nbits[256];
    UINT8 look_sym[256];
} d_derived_tbl;

extern JHUFF_TBL *htbl;
extern d_derived_tbl *dtbl;
extern int p;
extern int l;
extern unsigned int huffcode[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 prev_min = 0;
    INT32 running_p = p;

    for (l = 1; l <= 16; l++) {
        boolean has_bits = (htbl->bits[l] != 0);
        INT32 current_min = has_bits ? huffcode[running_p] : 0;
        INT32 next_p = has_bits ? running_p + htbl->bits[l] : running_p;
        INT32 current_max = has_bits ? huffcode[next_p - 1] : -1;

        dtbl->mincode[l] = current_min;
        dtbl->maxcode[l] = current_max;
        if (has_bits) {
            dtbl->valptr[l] = running_p;
            running_p = next_p;
        } else {
            dtbl->valptr[l] = 0;
        }

        prev_min = current_min;
    }
    p = running_p;
}
