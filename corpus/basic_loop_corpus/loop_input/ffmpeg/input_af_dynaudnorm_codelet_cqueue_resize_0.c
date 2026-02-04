#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct cqueue {
    double *elements;
    int size;
    int max_size;
    int nb_elements;
} cqueue;

cqueue *q;
int side;

void init_vars() {
    side = 1 << 20; // ~1 million elements, suitable for ~0.01s runtime
    q = (cqueue *)malloc(sizeof(cqueue));
    q->max_size = side + 1;
    q->size = side;
    q->nb_elements = 0;
    q->elements = (double *)malloc((side + 1) * sizeof(double));
}