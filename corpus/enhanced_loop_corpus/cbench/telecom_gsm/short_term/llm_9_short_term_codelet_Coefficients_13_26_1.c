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
for (i = 1; i <= 4; i += 2, LARpp_j_1 += 2, LARpp_j += 2, LARp += 2) {
    longword val1 = (longword)(*LARpp_j_1 >> 1);
    longword val2 = (longword)(*(LARpp_j_1 + 1) >> 1);
    longword val3 = (longword)(*LARpp_j >> 1);
    longword val4 = (longword)(*(LARpp_j + 1) >> 1);

    ltmp = val1 + val3;
    *LARp = ((ulongword)(ltmp - (-32768)) > 65535) ? (ltmp > 0 ? 32767 : -32768) : ltmp;

    if (i + 1 <= 4) {
        ltmp = val2 + val4;
        *(LARp + 1) = ((ulongword)(ltmp - (-32768)) > 65535) ? (ltmp > 0 ? 32767 : -32768) : ltmp;
    }
}
}
