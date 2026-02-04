#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (1 << 17)  // 128KB of data (each unsigned long is 8 bytes)

size_t i;
size_t mtop = DATA_SIZE;
unsigned long borrow = 1;
unsigned long carry;
unsigned long ta;
unsigned long mask;
unsigned long *rp;
unsigned long *ap;

void init_vars() {
    ap = aligned_alloc(32, DATA_SIZE * sizeof(unsigned long));
    rp = aligned_alloc(32, DATA_SIZE * sizeof(unsigned long));

    if (!ap || !rp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        ap[idx] = 0xABCDEF0123456789UL ^ idx;
        rp[idx] = 0xFEDCBA9876543210UL ^ idx;
    }

    i = 0;
    mask = 0 - borrow;
    carry = 0;
}