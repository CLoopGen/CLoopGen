#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ni;
int *right;
int *p;
int i;

static int *right_buffer;
static int *p_buffer;

void init_vars() {
    ni = 16777216; // 64 MB of data (16M integers, 4 bytes each)

    right_buffer = (int *)calloc(ni, sizeof(int));
    p_buffer = (int *)malloc(ni * sizeof(int));

    if (!right_buffer || !p_buffer) {
        exit(1);
    }

    for (int j = 0; j < ni; ++j) {
        p_buffer[j] = rand();
    }

    right = right_buffer;
    p = p_buffer;
}