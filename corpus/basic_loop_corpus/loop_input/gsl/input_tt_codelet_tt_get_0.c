#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long mag01[2] = {0x0UL, 0x9908b0dfUL};
unsigned long *x;
int i;

void init_vars() {
    size_t data_size = 1 << 24; // 16MB of data
    x = (unsigned long *)aligned_alloc(64, data_size * sizeof(unsigned long));
    if (!x) exit(1);

    for (size_t idx = 0; idx < data_size; idx++) {
        x[idx] = idx * 0xdeadbeefUL;
    }

    i = 0;
}