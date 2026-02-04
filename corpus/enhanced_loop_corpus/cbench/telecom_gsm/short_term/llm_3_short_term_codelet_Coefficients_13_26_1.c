#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

typedef unsigned long ulongword;

extern word *LARpp_j_1;
extern word *LARpp_j;
extern word *LARp;
extern int i;
extern longword ltmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Access with Array Indexing (using offset from base pointer)
    word *base_LARpp_j_1 = LARpp_j_1;
    word *base_LARpp_j   = LARpp_j;
    word *base_LARp      = LARp;
    
    for (i = 0; i < 8; i++) {
        longword val1 = (longword)(base_LARpp_j_1[i] >> 1);
        longword val2 = (longword)(base_LARpp_j[i] >> 1);
        ltmp = val1 + val2;
        base_LARp[i] = ((ulongword)(ltmp - ((-32767) - 1)) > (32767) - ((-32767) - 1))
                        ? (ltmp > 0 ? 32767 : (-32767) - 1)
                        : ltmp;
    }
}
