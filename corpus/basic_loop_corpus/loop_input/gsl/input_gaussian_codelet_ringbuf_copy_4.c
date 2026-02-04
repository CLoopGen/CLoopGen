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
int n = 0;
int i = 0;

void init_vars() {
    n = 1 << 24; // 16M elements ~128 MB of data (each double is 8 bytes)

    dest = (double*)aligned_alloc(32, n * sizeof(double));
    b = (ringbuf*)aligned_alloc(32, sizeof(ringbuf));

    b->size = 1 << 23; // Ring buffer size: 8M elements
    b->head = b->size - 1000000; // Ensure (head + i) % size stays valid for i in [0, n)
    b->tail = 0;
    b->array = (ringbuf_type_t*)aligned_alloc(32, b->size * sizeof(ringbuf_type_t));

    for (int idx = 0; idx < b->size; ++idx) {
        b->array[idx] = (double)(idx & 0xFFFF);
    }

    for (int idx = 0; idx < n; ++idx) {
        dest[idx] = 0.0;
    }
}