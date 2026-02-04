#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int *a;
int i;
int j;
int tmp;
int v;
int numswaps;

static int *a_data;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data: 262144 integers (assuming 4 bytes per int)
    a_data = aligned_alloc(32, data_size * sizeof(int));
    
    if (!a_data) {
        exit(1);
    }

    // Initialize array with random data
    for (size_t k = 0; k < data_size; ++k) {
        a_data[k] = rand();
    }

    // Set pivot value v to median estimate
    v = a_data[data_size / 2];

    // Initialize indices for partitioning
    i = -1;
    j = data_size;

    // Assign external pointer
    a = a_data;

    // Reset swap counter
    numswaps = 0;
}