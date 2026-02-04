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
gsl_permutation *pa;
gsl_permutation *pb;
size_t i;
size_t size;

void init_vars() {
    size = 65536; // Approximately 1MB of data (65536 * 8 bytes per size_t)

    p = malloc(sizeof(gsl_permutation));
    pa = malloc(sizeof(gsl_permutation));
    pb = malloc(sizeof(gsl_permutation));

    p->size = size;
    pa->size = size;
    pb->size = size;

    p->data = malloc(size * sizeof(size_t));
    pa->data = malloc(size * sizeof(size_t));
    pb->data = malloc(size * sizeof(size_t));

    for (i = 0; i < size; i++) {
        pa->data[i] = i;
        pb->data[i] = size - i - 1;
    }

    for (i = 0; i < size; i++) {
        p->data[i] = 0;
    }
}