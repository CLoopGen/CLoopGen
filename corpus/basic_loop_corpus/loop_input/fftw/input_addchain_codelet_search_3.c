#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n;
int *A;
int i;

void init_vars() {
    n = 64 * 1024 * 1024 / sizeof(int);  // ~256 MB of data for int array
    A = (int*)calloc(n, sizeof(int));
    if (!A) {
        exit(1);
    }
}