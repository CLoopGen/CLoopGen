#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};

typedef struct gsl_permutation_struct gsl_permutation;

gsl_permutation *p;
size_t n;
size_t i;

void init_vars() {
    n = 20000000; // ~20 million elements, targets ~0.01 sec on modern CPU
    p = (gsl_permutation *)malloc(sizeof(gsl_permutation));
    if (!p) exit(1);
    p->size = n;
    p->data = (size_t *)malloc(n * sizeof(size_t));
    if (!p->data) exit(1);
}