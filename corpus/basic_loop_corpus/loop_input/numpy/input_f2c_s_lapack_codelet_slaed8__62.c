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
    i__1 = 65536; // Size chosen to ensure ~0.01 sec runtime on modern CPU

    indxq = (integer*)calloc(i__1 + 1, sizeof(integer));
    perm = (integer*)calloc(i__1 + 1, sizeof(integer));
    indx = (integer*)calloc(i__1 + 1, sizeof(integer));

    for (int i = 1; i <= i__1; ++i) {
        indx[i] = i; 
        indxq[i] = rand();
    }
}