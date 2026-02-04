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
extern int l;
extern unsigned int huffcode[257];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using local stride simulation
    // We traverse the same range but simulate a forward-stride access by caching values
    JLONG temp_offsets[17] = {0};
    JLONG temp_maxcodes[17] = {0};
    int updated[17] = {0};

    for (l = 1; l <= 16; l++) {
        int bit_val = htbl->bits[l];
        if (bit_val) {
            temp_offsets[l] = (JLONG)p - (JLONG)huffcode[p];
            p += bit_val;
            temp_maxcodes[l] = huffcode[p - 1];
            updated[l] = 1;
        } else {
            temp_maxcodes[l] = -1;
            updated[l] = 1;
        }
    }

    // Flush cached values back to dtbl in a sequential write pattern
    for (int i = 1; i <= 16; i++) {
        if (updated[i]) {
            dtbl->valoffset[i] = temp_offsets[i];
            dtbl->maxcode[i] = temp_maxcodes[i];
        }
    }
}
