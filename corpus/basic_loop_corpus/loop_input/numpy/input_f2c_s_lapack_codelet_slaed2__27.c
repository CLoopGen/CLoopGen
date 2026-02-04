#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indxq;
integer *indx;
integer *indxc;
integer i__1;
integer i__;

void init_vars() {
    i__1 = 262144; 

    indxq = (integer *)calloc(i__1 + 1, sizeof(integer));
    indx = (integer *)calloc(i__1 + 1, sizeof(integer));
    indxc = (integer *)calloc(i__1 + 1, sizeof(integer));

    for (integer i = 1; i <= i__1; ++i) {
        indxc[i] = i;
        indxq[i] = rand();
    }
}