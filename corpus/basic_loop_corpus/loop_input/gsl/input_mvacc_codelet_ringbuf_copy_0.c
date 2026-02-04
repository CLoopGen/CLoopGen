#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double ringbuf_type_t;

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
    n = 32 * 1024 * 1024 / sizeof(double);  // ~256 MB total data size
    b = (ringbuf *)malloc(sizeof(ringbuf));
    b->size = n;
    b->head = 0;
    b->tail = 0;
    b->array = (ringbuf_type_t *)aligned_alloc(32, sizeof(ringbuf_type_t) * b->size);
    dest = (double *)aligned_alloc(32, sizeof(double) * n);

    for (int j = 0; j < b->size; ++j) {
        b->array[j] = (double)(j & 1023) + 1.0;
    }
}