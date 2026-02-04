#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

static unsigned long rp_array[262144]; // ~1MB assuming 4-byte unsigned long (adjust size for ~0.01s runtime)
static unsigned long d_array[1024];

BIGNUM *r;
unsigned long *rp = rp_array;
unsigned long v;
int max = 262144;
int i;
unsigned int rtop;

void init_vars() {
    r = (BIGNUM *)malloc(sizeof(BIGNUM));
    if (!r) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    r->d = d_array;
    r->top = 512; // ensures (i - rtop) can be negative and positive
    r->dmax = 1024;
    r->neg = 0;
    r->flags = 0;

    rp = rp_array;
    max = 262144;

    // Initialize rp array to non-zero values for observable effect
    for (int j = 0; j < max; j++) {
        rp[j] = 0xFFFFFFFFUL;
    }

    v = 0;
    i = 0;
    rtop = 0;
}