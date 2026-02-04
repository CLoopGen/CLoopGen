#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int integer;

integer *iwork;
integer j;
integer subpbs;

void init_vars() {
    subpbs = 1 << 26;  // Approximately 67 million elements, adjust for ~0.01s runtime
    size_t array_size = (subpbs * 2 + 1) * sizeof(integer);
    iwork = (integer*)aligned_alloc(32, array_size);
    if (!iwork) {
        exit(1);
    }

    for (integer i = 1; i <= subpbs * 2; ++i) {
        iwork[i] = rand() % 1000;
    }
}