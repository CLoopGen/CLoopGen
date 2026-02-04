#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t i;
size_t mtop;
unsigned long carry;
unsigned long *rp;
unsigned long *tp;

void init_vars() {
    const size_t data_size = 131072; // 128 KB of data
    mtop = data_size / sizeof(unsigned long);
    rp = (unsigned long *)aligned_alloc(64, data_size);
    tp = (unsigned long *)aligned_alloc(64, data_size);

    if (!rp || !tp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < mtop; idx++) {
        rp[idx] = 0xABCDEF0123456789ULL + idx;
        tp[idx] = 0x123456789ABCDEF0ULL ^ idx;
    }

    carry = 0x55AA55AA55AA55AAULL;

    for (size_t idx = 0; idx < mtop; idx++) {
        ((volatile unsigned long *)tp)[idx] = tp[idx];
    }
}