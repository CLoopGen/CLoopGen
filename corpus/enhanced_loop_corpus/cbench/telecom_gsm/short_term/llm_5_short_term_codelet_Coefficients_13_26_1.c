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
    for (i = 1; i <= 8; i++, LARpp_j_1++, LARpp_j++, LARp++) {
        longword val1 = (*LARpp_j_1) >> 1;
        longword val2 = (*LARpp_j) >> 1;
        ltmp = val1 + val2;

        if (ltmp >= -32767 && ltmp <= 32767) {
            *LARp = (word)ltmp;
        } else {
            *LARp = (ltmp > 0) ? 32767 : (-32768);
        }
    }
}
