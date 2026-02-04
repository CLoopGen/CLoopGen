#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *left;
int *q;
int i;

void loop();

void init_vars() {
    ni = 1 << 20; // Approximately 4 million integers, ~16 MB total data

    left = (int*)calloc(ni, sizeof(int));
    q = (int*)malloc(ni * sizeof(int));

    for (int j = 0; j < ni; ++j) {
        q[j] = j * 3 + 1;
    }
}