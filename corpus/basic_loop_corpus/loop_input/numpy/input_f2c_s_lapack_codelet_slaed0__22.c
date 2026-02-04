#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef int integer;

integer *iwork;
integer i__1;
integer i__;
integer igivpt;
integer iprmpt;

static size_t data_size = 128 * 1024 * 1024; // 128 MB

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    i__1 = 32 * 1024 * 1024; // Set loop count to 32M iterations for ~0.01s runtime

    iwork = (integer*)calloc(data_size / sizeof(integer), sizeof(integer));
    if (!iwork) {
        exit(1);
    }

    iprmpt = 0;
    igivpt = i__1 + 1;

    size_t required_size = igivpt + i__1 + 1;
    if (required_size > data_size / sizeof(integer)) {
        iwork = (integer*)realloc(iwork, required_size * sizeof(integer));
        if (!iwork) {
            exit(1);
        }
        memset(iwork + data_size / sizeof(integer), 0, (required_size - data_size / sizeof(integer)) * sizeof(integer));
        data_size = required_size * sizeof(integer);
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    if (elapsed > 0.01) {
        i__1 = (i__1 * 0.01) / elapsed;
    }
}