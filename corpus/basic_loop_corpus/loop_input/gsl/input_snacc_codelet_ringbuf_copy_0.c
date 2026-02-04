#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double snacc_type_t;
typedef snacc_type_t ringbuf_type_t;

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
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for ~0.01 sec runtime estimate
    n = data_size / sizeof(snacc_type_t);

    b = (ringbuf*)malloc(sizeof(ringbuf));
    b->size = n + 1000; // Ensure size is larger than n to avoid modulo overflow issues
    b->head = 500;       // Leave space at the beginning
    b->tail = (b->head + n - 1) % b->size;
    b->array = (ringbuf_type_t*)malloc(b->size * sizeof(ringbuf_type_t));

    dest = (double*)malloc(n * sizeof(double));

    for (int j = 0; j < b->size; ++j) {
        b->array[j] = (ringbuf_type_t)(j * 1.5);
    }
    for (int j = 0; j < n; ++j) {
        dest[j] = 0.0;
    }
}