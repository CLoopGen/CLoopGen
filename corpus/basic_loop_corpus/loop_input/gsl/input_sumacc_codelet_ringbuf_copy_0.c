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
    n = 65536 * 4;  // ~512KB for dest and accessed portion of b->array (assuming double is 8 bytes)

    b = (ringbuf*)malloc(sizeof(ringbuf));
    b->size = n;
    b->head = 0;
    b->tail = 0;
    b->array = (ringbuf_type_t*)malloc((size_t)b->size * sizeof(ringbuf_type_t));

    dest = (double*)malloc((size_t)n * sizeof(double));

    for (int j = 0; j < b->size; ++j) {
        b->array[j] = (ringbuf_type_t)(j * 2);
    }

    for (int j = 0; j < n; ++j) {
        dest[j] = 0.0;
    }
}