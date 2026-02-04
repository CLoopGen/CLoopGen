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
for (j = i__1; j >= 2; --j) {
    jp = idxp[j];
    perm[j] = idxq[idx[jp] + 1];
    if (perm[j] <= nlp1) {
        --perm[j];
    }
}
}
