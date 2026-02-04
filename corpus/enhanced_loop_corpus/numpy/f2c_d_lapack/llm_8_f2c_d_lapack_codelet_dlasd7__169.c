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
    for (j = 2; j <= i__1; j += 2) {
        if (j + 1 <= i__1) {
            jp = idxp[j];
            perm[j] = idxq[idx[jp] + 1];
            if (perm[j] <= nlp1) {
                --perm[j];
            }
            jp = idxp[j + 1];
            perm[j + 1] = idxq[idx[jp] + 1];
            if (perm[j + 1] <= nlp1) {
                --perm[j + 1];
            }
        } else {
            jp = idxp[j];
            perm[j] = idxq[idx[jp] + 1];
            if (perm[j] <= nlp1) {
                --perm[j];
            }
        }
    }
}
