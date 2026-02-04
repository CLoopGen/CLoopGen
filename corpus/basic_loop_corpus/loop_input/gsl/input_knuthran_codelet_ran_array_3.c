#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long *aa;
unsigned long *ran_x;
unsigned int i;
unsigned int j;

void init_vars() {
    size_t data_size = 1 << 20; // Approximately 1MB of data

    aa = (unsigned long *)aligned_alloc(64, data_size * sizeof(unsigned long));
    ran_x = (unsigned long *)aligned_alloc(64, data_size * sizeof(unsigned long));

    for (size_t idx = 0; idx < data_size; idx++) {
        aa[idx] = (unsigned long)rand();
        ran_x[idx] = (unsigned long)rand();
    }

    i = 37;
    j = 100;
}