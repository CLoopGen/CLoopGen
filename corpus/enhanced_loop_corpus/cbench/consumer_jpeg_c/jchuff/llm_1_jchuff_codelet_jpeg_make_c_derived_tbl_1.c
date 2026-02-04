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
    // Variant 2: Decreased loop nesting depth — although original has no nesting, we ensure flatness
    // and unroll the loop partially to reduce effective iterations, simulating lower depth impact
    // This version uses partial unrolling with a step of 2 to reduce iteration count
    // and eliminate any potential for deeper structure
    p = 0;
    // Process two elements per iteration if possible
    for (; p <= lastp - 2; p += 2) {
        dtbl->ehufco[htbl->huffval[p]] = huffcode[p];
        dtbl->ehufsi[htbl->huffval[p]] = huffsize[p];
        dtbl->ehufco[htbl->huffval[p+1]] = huffcode[p+1];
        dtbl->ehufsi[htbl->huffval[p+1]] = huffsize[p+1];
    }
    // Handle remaining element if lastp is odd
    if (p == lastp - 1) {
        dtbl->ehufco[htbl->huffval[p]] = huffcode[p];
        dtbl->ehufsi[htbl->huffval[p]] = huffsize[p];
    }
}
