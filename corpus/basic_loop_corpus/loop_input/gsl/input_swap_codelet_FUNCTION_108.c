#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

size_t N = 64 * 1024 * 1024 / sizeof(int); // ~256 MB of data
int *ATp;
size_t i;

void init_vars() {
    ATp = (int*)calloc(N + 1, sizeof(int));
    if (!ATp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}