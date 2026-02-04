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

static unsigned long *a_d_ptr;
static unsigned long *s_d_ptr;
BIGNUM *a;
BIGNUM *s;
int i;

void init_vars() {
    const int data_size = 2048;
    const int total_elements = 2 * data_size;

    a_d_ptr = (unsigned long *)calloc(data_size, sizeof(unsigned long));
    s_d_ptr = (unsigned long *)calloc(total_elements, sizeof(unsigned long));
    a = (BIGNUM *)malloc(sizeof(BIGNUM));
    s = (BIGNUM *)malloc(sizeof(BIGNUM));

    if (!a_d_ptr || !s_d_ptr || !a || !s) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < data_size; idx++) {
        a_d_ptr[idx] = (unsigned long)(0xABCDEF0123456789ULL ^ ((uint64_t)idx << 10));
    }

    a->d = a_d_ptr;
    a->top = data_size;
    a->dmax = data_size;
    a->neg = 0;
    a->flags = 0;

    s->d = s_d_ptr;
    s->top = total_elements;
    s->dmax = total_elements;
    s->neg = 0;
    s->flags = 0;
}