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
    integer stride = 4;
    for (j = 2; j <= i__1; j += stride) {
        for (integer k = 0; k < stride && (j + k) <= i__1; ++k) {
            integer curr_j = j + k;
            jp = idxp[curr_j];
            perm[curr_j] = idxq[idx[jp]];
            perm[curr_j] += 2;
            if (perm[curr_j] > nlp1) {
                perm[curr_j] -= 3;
            }
        }
    }
}
