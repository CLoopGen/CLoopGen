#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *n1;
integer *indxq;
integer i__1;
integer i__;
integer n1p1;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for indxq

    // Allocate indxq array
    indxq = (integer*)calloc(data_size, sizeof(integer));
    if (!indxq) {
        exit(1);
    }

    // Allocate and initialize n1
    n1 = (integer*)malloc(sizeof(integer));
    if (!n1) {
        exit(1);
    }
    *n1 = 1000;

    // Set loop bounds to ensure valid access within allocated indxq
    n1p1 = 1;
    i__1 = data_size - 1;
}