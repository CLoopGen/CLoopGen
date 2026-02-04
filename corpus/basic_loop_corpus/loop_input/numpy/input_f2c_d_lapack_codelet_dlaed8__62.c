#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indxq;
integer *perm;
integer *indx;
integer i__1;
integer j;

void init_vars() {
    i__1 = 65536; // Size chosen to make loop take ~0.01s

    indxq = (integer*)calloc(i__1 + 1, sizeof(integer));
    perm = (integer*)calloc(i__1 + 1, sizeof(integer));
    indx = (integer*)calloc(i__1 + 1, sizeof(integer));

    for (integer k = 1; k <= i__1; ++k) {
        indx[k] = k;
        indxq[k] = rand();
    }
}