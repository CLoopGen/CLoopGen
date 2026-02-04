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
    for (i = 1; i <= 4; i++) {
        for (int k = 0; k < 2; k++, LARpp_j_1++, LARpp_j++, LARp++) {
            *LARp = ((ulongword)((ltmp = (longword)(((*LARpp_j_1) >> (2))) + (longword)(((*LARpp_j) >> (2)))) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
            *LARp = ((ulongword)((ltmp = (longword)(*LARp) + (longword)(((*LARpp_j) >> (1)))) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
        }
    }
}
