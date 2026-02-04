#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t N = 10000000; // Approximately 40 MB of data for int array (10M elements)
int *ATp;
size_t i;

void init_vars() {
    ATp = (int*)calloc(N + 1, sizeof(int));
    if (!ATp) {
        exit(1);
    }
}