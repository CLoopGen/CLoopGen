#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long *aa;
unsigned long *ran_x;
unsigned int i;
unsigned int j;

void init_vars() {
    size_t data_size = 1 << 20; // ~8MB of data (each unsigned long is 8 bytes)
    aa = (unsigned long*)aligned_alloc(64, data_size * sizeof(unsigned long));
    ran_x = (unsigned long*)aligned_alloc(64, 37 * sizeof(unsigned long));

    if (!aa || !ran_x) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        aa[idx] = rand() % ((1UL << 30) - 1);
    }

    for (size_t idx = 0; idx < 37; idx++) {
        ran_x[idx] = 0;
    }

    i = 0;
    j = 100; // ensures j-100 >= 0 and j-37 >= 0 at start, since we access aa[j-100] and aa[j-37]
}