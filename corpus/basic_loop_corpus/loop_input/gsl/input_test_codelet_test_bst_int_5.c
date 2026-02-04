#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t n = 64 * 1024 * 1024 / sizeof(int); // ~256 MB of int data
int *data;
int *sorted_data;
int i;

void init_vars() {
    data = (int*)malloc(n * sizeof(int));
    sorted_data = (int*)malloc(n * sizeof(int));

    if (!data || !sorted_data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < n; ++idx) {
        data[idx] = rand();
    }
}