#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef int Int32;

Int32 *base;
Int32 i;

void init_vars() {
    const size_t data_size = 1 << 24; // 16 MB of data
    base = (Int32*)calloc(data_size, sizeof(Int32));
    if (!base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    i = 0;
}