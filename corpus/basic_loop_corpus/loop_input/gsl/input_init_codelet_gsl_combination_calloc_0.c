#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct gsl_combination_struct {
    size_t n;
    size_t k;
    size_t *data;
};

typedef struct gsl_combination_struct gsl_combination;

size_t k = 20000000; // ~160MB for size_t array (assuming 8 bytes per element)
size_t i;
gsl_combination *c;

void init_vars() {
    c = (gsl_combination *)malloc(sizeof(gsl_combination));
    if (!c) exit(1);
    c->n = k;
    c->k = k;
    c->data = (size_t *)malloc(k * sizeof(size_t));
    if (!c->data) exit(1);
}