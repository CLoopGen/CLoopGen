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
    // Variant 1: Increased loop nesting depth by splitting the original loop into two nested loops
    // Outer loop processes blocks of 16 elements (or smaller for the last block)
    int i, j;
    int block_size = 16;
    for (i = 0; i < (lastp + block_size - 1) / block_size; i++) {
        for (j = 0; j < block_size; j++) {
            p = i * block_size + j;
            if (p >= lastp) break;
            dtbl->ehufco[htbl->huffval[p]] = huffcode[p];
            dtbl->ehufsi[htbl->huffval[p]] = huffsize[p];
        }
    }
}
