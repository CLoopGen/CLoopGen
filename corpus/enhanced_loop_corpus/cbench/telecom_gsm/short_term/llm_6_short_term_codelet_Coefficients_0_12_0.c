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
    word temp1, temp2;
    for (i = 1; i <= 8; i++, LARp++, LARpp_j_1++, LARpp_j++) {
        temp1 = (*LARpp_j_1) >> 2;
        temp2 = (*LARpp_j) >> 2;
        ltmp = (longword)temp1 + (longword)temp2;
        *LARp = ((ulongword)(ltmp - ((-32767) - 1)) > (32767) - ((-32767) - 1)) 
                ? (ltmp > 0 ? 32767 : ((-32767) - 1)) 
                : ltmp;

        temp1 = *LARp;
        temp2 = (*LARpp_j_1) >> 1;
        ltmp = (longword)temp1 + (longword)temp2;
        *LARp = ((ulongword)(ltmp - ((-32767) - 1)) > (32767) - ((-32767) - 1)) 
                ? (ltmp > 0 ? 32767 : ((-32767) - 1)) 
                : ltmp;
    }
}
