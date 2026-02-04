#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indxq;
integer i__1;
integer i__;

void init_vars() {
    i__1 = 20000000; // Size to target ~0.01 sec runtime on modern CPU
    indxq = (integer*)calloc(i__1 + 1, sizeof(integer));
}

// End of file