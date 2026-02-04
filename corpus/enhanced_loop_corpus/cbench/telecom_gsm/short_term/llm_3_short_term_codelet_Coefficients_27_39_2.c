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
word index_map[] = {0, 2, 4, 6, 8, 10, 12, 14};
for (i = 0; i < 8; i++, LARp++) {
    int idx = index_map[i];
    *LARp = ((ulongword)((ltmp = (longword)((LARpp_j_1[idx] >> 2)) + (longword)((LARpp_j[idx] >> 2))) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
    *LARp = ((ulongword)((ltmp = (longword)(*LARp) + (longword)((LARpp_j[idx+1] >> 1))) - ((-32767) - 1)) > (32767) - ((-32767) - 1) ? (ltmp > 0 ? (32767) : ((-32767) - 1)) : ltmp);
}
}
