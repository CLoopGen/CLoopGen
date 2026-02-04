#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indx;
integer i__1;
integer j;

void init_vars() {
    i__1 = 20000000; // Size to target ~0.01 sec runtime (adjust based on typical CPU speed)
    indx = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (indx == NULL) {
        exit(1);
    }
}