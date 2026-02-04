#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n = 1024;
int m = 256;
int *in_map;

void init_vars() {
    size_t total_size = (size_t)m * n;
    in_map = (int*)calloc(total_size, sizeof(int));
    if (!in_map) {
        exit(1);
    }
}