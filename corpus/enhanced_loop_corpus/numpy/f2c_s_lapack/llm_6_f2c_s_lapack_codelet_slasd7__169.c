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
    integer temp;
    for (j = 2; j <= i__1; ++j) {
        jp = idxp[j];
        temp = idxq[idx[jp] + 1];
        perm[j] = temp;
        if (perm[j] <= nlp1) {
            perm[j] = temp - 1;
        }
    }
}
