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

gsl_multiset *c;
size_t k = 262144; // Approximately 256K elements for ~0.01 sec runtime
size_t i;
size_t n = 1000;

void init_vars() {
    c = (gsl_multiset *)malloc(sizeof(gsl_multiset));
    c->n = n;
    c->k = k;
    c->data = (size_t *)malloc(k * sizeof(size_t));
}

// Variable name mappings to avoid conflicts with system symbols