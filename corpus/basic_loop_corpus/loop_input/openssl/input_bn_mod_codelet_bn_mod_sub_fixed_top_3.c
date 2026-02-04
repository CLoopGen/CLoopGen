#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t i;
size_t mtop;
unsigned long borrow;
unsigned long carry;
unsigned long ta;
unsigned long mask;
unsigned long *rp;
unsigned long *ap;

void init_vars() {
    const size_t data_size = 131072; // 128 KB of data (16384 unsigned longs, assuming 8 bytes each)

    mtop = data_size / sizeof(unsigned long);
    rp = aligned_alloc(32, data_size);
    ap = aligned_alloc(32, data_size);

    if (!rp || !ap) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < mtop; idx++) {
        rp[idx] = 0xdeadbeefdeadbeefUL ^ idx;
        ap[idx] = 0xc0dec0dec0dec0deUL ^ idx;
    }

    borrow = 1;
    carry = 0;
    ta = 0;
    mask = 0 - borrow;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}