#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int N = 65536 * 4; // Approximately 256K elements, adjust for ~0.01 sec runtime
int *cindex;

void init_vars() {
    cindex = (int*)malloc(N * sizeof(int));
    if (!cindex) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}