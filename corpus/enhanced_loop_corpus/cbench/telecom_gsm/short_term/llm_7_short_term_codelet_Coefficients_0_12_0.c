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
    word *local_LARp = LARp;
    word *local_LARpp_j_1 = LARpp_j_1;
    word *local_LARpp_j = LARpp_j;
    longword local_ltmp;
    for (i = 1; i <= 8; i++) {
        local_ltmp = (longword)((*local_LARpp_j_1 >> 2)) + (longword)((*local_LARpp_j >> 2));
        *local_LARp = ((ulongword)(local_ltmp - (-32768)) > 65535)
                      ? (local_ltmp > 0 ? 32767 : -32768)
                      : local_ltmp;

        local_ltmp = (longword)(*local_LARp) + (longword)(*local_LARpp_j_1 >> 1);
        *local_LARp = ((ulongword)(local_ltmp - (-32768)) > 65535)
                      ? (local_ltmp > 0 ? 32767 : -32768)
                      : local_ltmp;

        local_LARp++;
        local_LARpp_j_1++;
        local_LARpp_j++;
    }
    LARp = local_LARp;
    LARpp_j_1 = local_LARpp_j_1;
    LARpp_j = local_LARpp_j;
}
