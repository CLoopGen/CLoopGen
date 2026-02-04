#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indx;
integer i__1;
integer j;

void init_vars() {
    i__1 = 20000000; // Size to make loop take ~0.01 seconds
    indx = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (!indx) {
        exit(1);
    }
}