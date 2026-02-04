#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indx;
integer i__1;
integer j;

void init_vars() {
    i__1 = 25000000; // Size to target ~0.01 sec runtime on modern CPU
    indx = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (!indx) {
        exit(1);
    }
}