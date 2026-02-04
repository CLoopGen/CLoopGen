#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int j;
int n = 67108864; // Approximately 256MB / (sizeof(int) * 2), ensures ~0.01s runtime
int *start_row;
int *start_idx;

void init_vars() {
    start_row = (int*)calloc(n, sizeof(int));
    start_idx = (int*)calloc(n, sizeof(int));
}