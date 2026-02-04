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



void loop() {
    word *local_LARpp_j_1 = LARpp_j_1;
    word *local_LARpp_j = LARpp_j;
    word *local_LARp = LARp;
    longword prev_ltmp = 0;
    for (i = 1; i <= 8; i++, local_LARpp_j_1++, local_LARpp_j++, local_LARp++) {
        ltmp = (longword)((*local_LARpp_j_1 >> 1)) + (longword)((*local_LARpp_j >> 1)) + (prev_ltmp & 1);
        *local_LARp = ((ulongword)(ltmp - ((-32767) - 1)) > (32767) - ((-32767) - 1)
                       ? (ltmp > 0 ? 32767 : (-32767) - 1)
                       : ltmp);
        prev_ltmp = ltmp;
    }
}
