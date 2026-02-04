#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
int *aindex;
int i;

void init_vars() {
    N = 65536; // Size chosen to be large enough for measurable execution time (~0.01 sec)
    aindex = (int*)calloc(N, sizeof(int));
    if (!aindex) {
        exit(1);
    }
    i = 0;
}