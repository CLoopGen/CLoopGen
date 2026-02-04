#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *iwork;
integer i__1;
integer j;

void init_vars() {
    i__1 = 65536;  // Size chosen to make loop take ~0.01 seconds
    iwork = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (!iwork) {
        exit(1);
    }
}