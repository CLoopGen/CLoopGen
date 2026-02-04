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
for (i = 1; i <= 4; i += 2, LARp += 2, LARpp_j_1 += 2, LARpp_j += 2) {
    longword temp1 = (longword)((*LARpp_j_1) >> 2) + (longword)((*LARpp_j) >> 2);
    longword temp2 = (temp1 - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (temp1 > 0 ? 32767 : (-32767)-1) : temp1;
    *LARp = (word)temp2;

    longword temp3 = (longword)((*(LARpp_j_1 + 1)) >> 2) + (longword)((*(LARpp_j + 1)) >> 2);
    longword temp4 = (temp3 - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (temp3 > 0 ? 32767 : (-32767)-1) : temp3;
    *(LARp + 1) = (word)temp4;

    *LARp = ((ulongword)((ltmp = (longword)(*LARp) + (longword)((*LARpp_j_1) >> 1)) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? 32767 : (-32767)-1) : ltmp);
}
}
