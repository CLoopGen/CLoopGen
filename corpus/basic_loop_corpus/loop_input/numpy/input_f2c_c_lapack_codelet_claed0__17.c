#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *iwork;
integer j;
integer subpbs;

void init_vars() {
    const size_t data_size = 1 << 20; // Approximately 4MB of data (1M integers)
    subpbs = (data_size / sizeof(integer)) / 2; // Ensure we stay within bounds

    iwork = (integer*)aligned_alloc(32, data_size);
    if (!iwork) {
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(integer); ++i) {
        iwork[i] = rand() % 1000;
    }
}