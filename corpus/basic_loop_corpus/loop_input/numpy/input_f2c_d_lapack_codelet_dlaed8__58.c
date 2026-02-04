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
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for indxq array (each integer 4 bytes)

    // Allocate large array for indxq
    indxq = (integer*)calloc(data_size, sizeof(integer));
    if (!indxq) {
        exit(1);
    }

    // Allocate and initialize cutpnt as a pointer to a single integer
    cutpnt = (integer*)malloc(sizeof(integer));
    if (!cutpnt) {
        exit(1);
    }
    *cutpnt = 1000; // Set cutpnt value

    // Set i__1 to ensure the loop runs over a valid range within allocated indxq
    i__1 = *cutpnt + (data_size - 1); // So that i__ goes up to just before the end of allocated space

    // Ensure i__1 does not exceed allocated size
    if (i__1 >= data_size) {
        i__1 = data_size - 1;
    }
}