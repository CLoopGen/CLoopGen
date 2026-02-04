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
    // Increase loop nesting depth by adding an outer loop that partitions the original range
    for (integer block = 2; block <= i__1; block += 10) {
        for (j = block; j <= i__1 && j < block + 10; ++j) {
            jp = idxp[j];
            perm[j] = idxq[idx[jp] + 1];
            if (perm[j] <= nlp1) {
                --perm[j];
            }
        }
    }
}
