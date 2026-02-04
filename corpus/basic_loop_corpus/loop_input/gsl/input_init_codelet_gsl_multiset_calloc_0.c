#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_multiset_struct {
    size_t n;
    size_t k;
    size_t *data;
};

typedef struct gsl_multiset_struct gsl_multiset;

size_t k = 134217728; // ~128MB of data (134217728 * sizeof(size_t))
size_t i;
gsl_multiset *c;

void init_vars() {
    c = (gsl_multiset *)malloc(sizeof(gsl_multiset));
    if (!c) exit(1);
    c->n = k;
    c->k = k;
    c->data = (size_t *)calloc(k, sizeof(size_t));
    if (!c->data) exit(1);
}