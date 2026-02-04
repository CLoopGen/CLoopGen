#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned int N;
int *dindex;
int i;

void init_vars() {
    N = 67108864; // Approximately 256MB for int array (67M elements * 4 bytes ≈ 256MB)
    dindex = (int*)aligned_alloc(32, N * sizeof(int));
    if (!dindex) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    memset(dindex, 0, N * sizeof(int));
}