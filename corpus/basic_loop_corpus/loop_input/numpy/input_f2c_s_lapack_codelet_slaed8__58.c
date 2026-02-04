#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *indxq;
integer *cutpnt;
integer i__1;
integer i__;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for indxq array (64M integers)

    // Allocate indxq array
    indxq = (integer*)calloc(data_size, sizeof(integer));
    if (!indxq) {
        exit(1);
    }

    // Allocate and initialize cutpnt as a single integer on heap
    cutpnt = (integer*)malloc(sizeof(integer));
    if (!cutpnt) {
        free(indxq);
        exit(1);
    }
    *cutpnt = 1000; // Example value

    // Set loop bounds: loop runs from *cutpnt + 1 to i__1 inclusive
    // Ensure i__1 is within allocated bounds of indxq
    i__1 = *cutpnt + 1000000; // Run 1M iterations

    // Validate that i__1 does not exceed allocated size
    if (i__1 >= (integer)data_size) {
        free(cutpnt);
        free(indxq);
        exit(1);
    }
}