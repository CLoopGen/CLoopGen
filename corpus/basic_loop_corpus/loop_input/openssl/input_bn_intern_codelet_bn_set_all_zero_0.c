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
static BIGNUM a_instance;
BIGNUM *a = &a_instance;
int i;

void init_vars() {
    const size_t data_size = 1024 * 256 / sizeof(unsigned long); // ~1MB
    d_array = (unsigned long *)calloc(data_size, sizeof(unsigned long));
    if (!d_array) {
        exit(1);
    }

    a->d = d_array;
    a->top = data_size / 2;
    a->dmax = data_size;
    a->neg = 0;
    a->flags = 0;
}