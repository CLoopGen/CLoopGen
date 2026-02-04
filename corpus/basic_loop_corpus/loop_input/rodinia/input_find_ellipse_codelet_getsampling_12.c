#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N = 134217728; // 128MB of data: 134217728 elements * 1 byte per int (approx)

int *cindex;
int i;

void init_vars() {
    cindex = (int*)malloc(N * sizeof(int));
    if (!cindex) {
        exit(1);
    }
}