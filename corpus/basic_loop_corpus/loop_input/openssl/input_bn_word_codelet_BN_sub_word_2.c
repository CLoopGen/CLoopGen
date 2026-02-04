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

static unsigned long *d_array;
BIGNUM *a;
unsigned long w;
int i;

void init_vars() {
    const size_t data_size = 131072; // ~128KB of data (16384 * 8 bytes per unsigned long)
    d_array = (unsigned long *)calloc(data_size / sizeof(unsigned long), sizeof(unsigned long));
    if (!d_array) {
        exit(1);
    }

    a = (BIGNUM *)malloc(sizeof(BIGNUM));
    if (!a) {
        exit(1);
    }

    a->d = d_array;
    a->top = (int)(data_size / sizeof(unsigned long));
    a->dmax = a->top;
    a->neg = 0;
    a->flags = 0;

    for (int j = 0; j < a->top; j++) {
        d_array[j] = (unsigned long)(j + 1) * 100; // Ensure decreasing values
    }

    w = (unsigned long)50;
    i = 0;

    // Ensure the loop will break within bounds
    // Set one element such that d[i] >= w eventually when w becomes 1
    // After several iterations w becomes 1 and then d[i] >= w will be true since all are positive
}