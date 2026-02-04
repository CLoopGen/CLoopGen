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
size_t k = 131072; // 128K elements to target ~0.01 sec runtime
size_t i;
size_t n = 262144;

void init_vars() {
    c = (gsl_combination*)malloc(sizeof(gsl_combination));
    if (!c) exit(1);

    c->n = n;
    c->k = k;
    c->data = (size_t*)malloc(k * sizeof(size_t));
    if (!c->data) exit(1);
}