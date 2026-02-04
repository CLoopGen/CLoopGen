#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double funcacc_type_t;
typedef funcacc_type_t ringbuf_type_t;

typedef struct {
    ringbuf_type_t *array;
    int head;
    int tail;
    int size;
} ringbuf;

double *dest;
ringbuf *b;
int n;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64 million doubles = ~512 MB total data
    n = data_size;

    dest = (double*)aligned_alloc(32, n * sizeof(double));
    if (!dest) exit(1);

    b = (ringbuf*)malloc(sizeof(ringbuf));
    if (!b) exit(1);

    b->size = data_size;
    b->head = 0;
    b->tail = 0;

    b->array = (ringbuf_type_t*)aligned_alloc(32, b->size * sizeof(ringbuf_type_t));
    if (!b->array) exit(1);

    for (size_t idx = 0; idx < b->size; ++idx) {
        b->array[idx] = (funcacc_type_t)(idx % 1000) + 0.5;
    }

    for (int j = 0; j < n; ++j) {
        dest[j] = 0.0;
    }
}