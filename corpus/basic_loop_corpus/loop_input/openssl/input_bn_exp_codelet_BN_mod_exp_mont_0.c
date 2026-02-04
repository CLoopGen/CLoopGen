#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <limits.h>

struct bignum_st {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
};

typedef struct bignum_st BIGNUM;

static unsigned long *alloc_d = NULL;
static unsigned long *m_d = NULL;

BIGNUM *m;
int i;
int j;
BIGNUM *r;

void init_vars() {
    const size_t target_size = 1024 * 128; // Aim for ~128KB of data
    const size_t element_size = sizeof(unsigned long);
    size_t num_elements = target_size / element_size;

    if (num_elements > INT_MAX) {
        num_elements = INT_MAX;
    }
    j = (int)num_elements;

    alloc_d = (unsigned long *)calloc(num_elements, element_size);
    m_d = (unsigned long *)calloc(num_elements, element_size);

    if (!alloc_d || !m_d) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        m_d[idx] = idx; // Initialize with non-zero predictable pattern
    }

    r = (BIGNUM *)malloc(sizeof(BIGNUM));
    m = (BIGNUM *)malloc(sizeof(BIGNUM));
    if (!r || !m) {
        exit(1);
    }

    r->d = alloc_d;
    r->top = j;
    r->dmax = j;
    r->neg = 0;
    r->flags = 0;

    m->d = m_d;
    m->top = j;
    m->dmax = j;
    m->neg = 0;
    m->flags = 0;
}