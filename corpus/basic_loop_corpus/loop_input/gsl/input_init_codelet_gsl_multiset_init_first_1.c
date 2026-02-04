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
size_t k;
size_t i;

void init_vars() {
    k = 16777216; // ~16.7 million elements to target ~0.01 sec on modern CPU

    c = (gsl_multiset*)malloc(sizeof(gsl_multiset));
    if (!c) exit(1);

    c->n = k;
    c->k = k;

    c->data = (size_t*)calloc(k, sizeof(size_t));
    if (!c->data) exit(1);
}