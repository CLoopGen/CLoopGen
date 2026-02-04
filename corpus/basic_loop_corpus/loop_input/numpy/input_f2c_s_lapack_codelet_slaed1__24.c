#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indxq;
integer i__1;
integer i__;

void init_vars() {
    i__1 = 262144; // Size to make loop take ~0.01s (adjust based on typical CPU speed and memory access)
    indxq = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (!indxq) {
        exit(1);
    }
}