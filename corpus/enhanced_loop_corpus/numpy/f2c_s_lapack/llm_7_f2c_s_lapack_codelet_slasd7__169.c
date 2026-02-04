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
        integer value = idxq[idx[jp] + 1];
        if (value > nlp1) {
            perm[j] = value;
        } else {
            perm[j] = value - 1;
        }
    }
}
