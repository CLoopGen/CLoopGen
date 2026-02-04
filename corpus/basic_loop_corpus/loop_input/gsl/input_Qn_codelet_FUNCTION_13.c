#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *right;
int *p;
int i;

static int *right_data;
static int *p_data;

void init_vars() {
    ni = 1 << 22; // Approximately 16 million elements, ~64 MB per array

    right_data = (int *)calloc(ni, sizeof(int));
    p_data = (int *)malloc(ni * sizeof(int));

    if (!right_data || !p_data) {
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        p_data[j] = j * 3 + 1;
    }

    right = right_data;
    p = p_data;
}