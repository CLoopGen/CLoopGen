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

BIGNUM *m;
int i;
int top;
BIGNUM tmp;

void init_vars() {
    const size_t data_size = 131072; // ~128KB: assuming 64-bit unsigned long (8 bytes per element)
    int num_elements = data_size / sizeof(unsigned long);

    // Allocate and initialize m's d array
    unsigned long *m_d_data = (unsigned long *)calloc(num_elements, sizeof(unsigned long));
    if (!m_d_data) exit(1);

    // Initialize m as a const-like structure (but not const since it's extern and needs assignment)
    m = (BIGNUM *)malloc(sizeof(BIGNUM));
    if (!m) exit(1);
    m->d = m_d_data;
    m->top = num_elements;
    m->dmax = num_elements;
    m->neg = 0;
    m->flags = 0;

    // Allocate and initialize tmp's d array
    unsigned long *tmp_d_data = (unsigned long *)calloc(num_elements, sizeof(unsigned long));
    if (!tmp_d_data) exit(1);

    tmp.d = tmp_d_data;
    tmp.top = num_elements;
    tmp.dmax = num_elements;
    tmp.neg = 0;
    tmp.flags = 0;

    // Set loop boundary
    top = m->top;

    // Ensure no out-of-bounds access in loop: i from 1 to top-1
    if (top > num_elements) top = num_elements;
}