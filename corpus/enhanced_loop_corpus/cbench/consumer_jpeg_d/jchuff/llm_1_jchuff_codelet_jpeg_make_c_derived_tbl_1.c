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
    // Variant 2: Decreased loop nesting depth — although original is flat, we ensure no unnecessary nesting
    // This variant unrolls the loop partially to reduce effective iterations and eliminate any potential implied nesting
    // Unroll by a factor of 4 for performance; remaining iterations handled in sequence
    p = 0;
    int remainder = lastp % 4;
    
    // Process multiples of 4 unrolled
    for (; p < lastp - remainder; p += 4) {
        dtbl->ehufco[htbl->huffval[p+0]] = huffcode[p+0];
        dtbl->ehufsi[htbl->huffval[p+0]] = huffsize[p+0];

        dtbl->ehufco[htbl->huffval[p+1]] = huffcode[p+1];
        dtbl->ehufsi[htbl->huffval[p+1]] = huffsize[p+1];

        dtbl->ehufco[htbl->huffval[p+2]] = huffcode[p+2];
        dtbl->ehufsi[htbl->huffval[p+2]] = huffsize[p+2];

        dtbl->ehufco[htbl->huffval[p+3]] = huffcode[p+3];
        dtbl->ehufsi[htbl->huffval[p+3]] = huffsize[p+3];
    }
    
    // Handle leftover elements without additional loops or nesting
    switch (remainder) {
        case 3:
            dtbl->ehufco[htbl->huffval[p+2]] = huffcode[p+2];
            dtbl->ehufsi[htbl->huffval[p+2]] = huffsize[p+2];
            // fall through
        case 2:
            dtbl->ehufco[htbl->huffval[p+1]] = huffcode[p+1];
            dtbl->ehufsi[htbl->huffval[p+1]] = huffsize[p+1];
            // fall through
        case 1:
            dtbl->ehufco[htbl->huffval[p+0]] = huffcode[p+0];
            dtbl->ehufsi[htbl->huffval[p+0]] = huffsize[p+0];
            break;
    }
}
