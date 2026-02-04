#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *idx;
extern integer *idxp;
extern integer *idxq;
extern integer *perm;
extern integer i__1;
extern integer j;
extern integer jp;
extern integer nlp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j <= i__1; ++j) {
    jp = idxp[j];
    integer temp_val = idxq[idx[jp] + 1];
    if (temp_val > nlp1) {
        perm[j] = temp_val;
    } else {
        perm[j] = temp_val - 1;
    }
}
}
