#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer i__1;
integer i__;
integer *indxq;

void init_vars() {
    i__1 = 134217728; // Approximately 512 MB of data (134217728 integers)
    indxq = (integer *)aligned_alloc(64, (i__1 + 1) * sizeof(integer));
    if (!indxq) {
        exit(1);
    }
}

void loop();