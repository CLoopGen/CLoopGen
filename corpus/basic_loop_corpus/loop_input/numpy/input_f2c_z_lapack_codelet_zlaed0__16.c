#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *iwork;
integer i__1;
integer i__;
integer igivpt;
integer iprmpt;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    iwork = (integer*)calloc(data_size, sizeof(integer));
    if (!iwork) {
        exit(1);
    }

    iprmpt = 0;
    igivpt = data_size / 2;
    i__1 = data_size / 4 - 1; // Ensure both iprmpt+i__ and igivpt+i__ stay in bounds
}