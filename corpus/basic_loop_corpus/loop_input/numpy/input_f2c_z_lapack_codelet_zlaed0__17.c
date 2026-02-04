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
    iwork = (integer*)calloc(data_size, sizeof(integer));
    if (!iwork) {
        exit(1);
    }

    for (size_t idx = 1; idx < data_size; ++idx) {
        iwork[idx] = rand() % 1000;
    }

    subpbs = (data_size >> 1) - 1; // Ensure j*2 and (j<<1)-1 stay within bounds
}