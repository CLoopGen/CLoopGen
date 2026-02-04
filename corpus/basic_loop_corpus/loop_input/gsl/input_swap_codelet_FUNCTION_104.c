#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t M = 131072; // Approximately 1MB of data for int (4 bytes per element)
int *ATp;
size_t j;

void init_vars() {
    ATp = (int*)calloc(M + 1, sizeof(int));
    if (!ATp) {
        exit(1);
    }
}