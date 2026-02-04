#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef int integer;

integer *indx;
integer i__1;
integer j;

void init_vars() {
    i__1 = 20000000;  // Adjusted to achieve ~0.01 seconds runtime

    indx = (integer*)calloc(i__1 + 1, sizeof(integer));
    if (indx == NULL) {
        exit(1);
    }
}