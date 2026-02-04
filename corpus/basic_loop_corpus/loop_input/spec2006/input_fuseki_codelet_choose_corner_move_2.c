#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *table;
int sum_of_weights;
int i;

void init_vars() {
    const int data_size = 1 << 20; // ~4MB of data (1M integers)
    table = (int*)calloc(data_size, sizeof(int));
    if (!table) {
        exit(1);
    }
    for (int j = 0; j < data_size; j++) {
        table[j] = 1; // Initialize with value 1
    }
    sum_of_weights = 0;
    i = 0;
}