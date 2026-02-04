#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};

typedef struct gsl_permutation_struct gsl_permutation;

size_t n = 134217728; // ~128MB of data (134217728 * 8 bytes per size_t)
size_t i;
gsl_permutation *p;

void init_vars() {
    p = (gsl_permutation*)malloc(sizeof(gsl_permutation));
    if (!p) exit(1);
    p->size = n;
    p->data = (size_t*)malloc(n * sizeof(size_t));
    if (!p->data) exit(1);
}