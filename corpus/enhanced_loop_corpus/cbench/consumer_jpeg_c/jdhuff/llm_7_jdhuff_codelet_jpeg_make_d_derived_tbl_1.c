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
    INT32 local_mincode[17];
    INT32 local_maxcode[18];
    int local_valptr[17];
    int updated_indices[17];
    int update_count = 0;
    int local_p = p;

    for (l = 1; l <= 16; l++) {
        if (htbl->bits[l]) {
            local_valptr[update_count] = l;
            updated_indices[update_count] = l;
            local_mincode[l] = huffcode[local_p];
            local_p += htbl->bits[l];
            local_maxcode[l] = huffcode[local_p - 1];
            update_count++;
        } else {
            local_maxcode[l] = -1;
        }
    }

    for (int i = 0; i < update_count; i++) {
        int idx = updated_indices[i];
        dtbl->valptr[idx] = local_valptr[i];
        dtbl->mincode[idx] = local_mincode[idx];
        dtbl->maxcode[idx] = local_maxcode[idx];
    }

    for (l = 1; l <= 16; l++) {
        if (htbl->bits[l] == 0) {
            dtbl->maxcode[l] = local_maxcode[l];
        }
    }
}
