#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 134217728; // ~128MB of data for int (assuming 4 bytes per int), ensures ~0.01 sec runtime
int *cindex;
int i;

void init_vars() {
    cindex = (int*)calloc(N, sizeof(int));
    if (!cindex) {
        exit(1);
    }
}