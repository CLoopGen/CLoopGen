#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *idx;
integer *idxp;
integer *idxq;
integer *perm;
integer i__1;
integer j;
integer jp;
integer nlp1;

void init_vars() {
    i__1 = 10000000;  // Adjust to target ~0.01 sec runtime

    idx = (integer*)calloc(i__1 + 1, sizeof(integer));
    idxp = (integer*)calloc(i__1 + 1, sizeof(integer));
    idxq = (integer*)calloc(i__1 + 2, sizeof(integer));  // +2 because of idx[jp]+1 access
    perm = (integer*)calloc(i__1 + 1, sizeof(integer));

    nlp1 = 5000000;

    for (int k = 0; k <= i__1; ++k) {
        idx[k] = rand() % (i__1 + 1);
        idxp[k] = rand() % (i__1 + 1);
        if (k <= i__1 + 1) {
            idxq[k] = rand() % (nlp1 + 1000000);
        }
        perm[k] = 0;
    }

    j = 0;
    jp = 0;
}