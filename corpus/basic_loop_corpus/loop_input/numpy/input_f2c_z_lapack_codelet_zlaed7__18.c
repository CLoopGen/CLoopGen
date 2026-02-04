#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indxq;
integer i__1;
integer i__;

void init_vars() {
    i__1 = 26214400; // Size to make loop run ~0.01 seconds (approx 100MB array on typical CPU)
    indxq = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (!indxq) {
        exit(1);
    }
}