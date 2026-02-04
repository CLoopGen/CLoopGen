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

gsl_combination *c;
size_t k = 10000000;  // 10^7 elements, targets ~0.01 sec runtime
size_t i;

static size_t *allocated_data;

void init_vars() {
    allocated_data = (size_t *)calloc(k, sizeof(size_t));
    if (!allocated_data) {
        exit(1);
    }

    c = (gsl_combination *)malloc(sizeof(gsl_combination));
    if (!c) {
        exit(1);
    }

    c->n = k;
    c->k = k;
    c->data = allocated_data;
}