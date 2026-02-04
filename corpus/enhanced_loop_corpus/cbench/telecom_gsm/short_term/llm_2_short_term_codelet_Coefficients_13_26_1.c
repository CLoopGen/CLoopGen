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
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 1; i <= 8; i++, LARpp_j_1 += 2, LARpp_j += 2, LARp += 2) {
        *LARp = ((ulongword)((ltmp = (longword)(((*LARpp_j_1) >> (1))) + (longword)(((*LARpp_j) >> (1)))) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
    }
}
