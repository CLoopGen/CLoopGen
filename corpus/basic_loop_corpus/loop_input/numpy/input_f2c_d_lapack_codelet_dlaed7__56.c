#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indxq;
integer i__1;
integer i__;

void init_vars() {
    i__1 = 10000000; // 10 million elements for ~0.01 sec runtime
    indxq = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (!indxq) {
        exit(1);
    }
}