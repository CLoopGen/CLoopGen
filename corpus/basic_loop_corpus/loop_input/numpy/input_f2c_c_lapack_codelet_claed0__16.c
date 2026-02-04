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
    const size_t data_size = 128 * 1024 * 1024; // 128 MB of data
    iwork = (integer*)calloc(data_size, sizeof(integer));
    if (!iwork) {
        exit(1);
    }

    i__1 = (data_size / 2) - 1; 
    igivpt = 0;
    iprmpt = data_size / 2 - (i__1 + 1);
}