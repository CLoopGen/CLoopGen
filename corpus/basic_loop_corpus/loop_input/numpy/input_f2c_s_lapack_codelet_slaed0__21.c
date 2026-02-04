#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *iwork;
integer j;
integer subpbs;

void init_vars() {
    const size_t data_size = 1 << 20; // ~4MB of data (1M integers)
    iwork = (integer*)aligned_alloc(32, data_size * sizeof(integer));
    if (!iwork) {
        exit(1);
    }

    subpbs = data_size / 4; // Ensure indices stay within bounds

    for (size_t i = 1; i <= data_size - 1; ++i) {
        iwork[i] = rand() % 1000;
    }
}