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

BIGNUM *a;
unsigned long w;
unsigned long l;
int i;

static unsigned long *d_array;
static BIGNUM a_storage;

void init_vars() {
    const size_t data_size = 1024 * 128; // Aim for ~128KB of data
    const int num_elements = data_size / sizeof(unsigned long);

    d_array = (unsigned long *)calloc(num_elements, sizeof(unsigned long));
    if (!d_array) exit(1);

    for (int j = 0; j < num_elements; j++) {
        d_array[j] = (unsigned long)(j * 7853 + 19); 
    }

    a_storage.d = d_array;
    a_storage.top = num_elements;
    a_storage.dmax = num_elements;
    a_storage.neg = 0;
    a_storage.flags = 0;

    a = &a_storage;
    w = 1;
    l = 0;
    i = 0;
}