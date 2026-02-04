#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef double qqracc_type_t;
typedef qqracc_type_t ringbuf_type_t;

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
    n = 67108864; // ~512 MB of data (67M * sizeof(double) ≈ 512MB), ensures ~0.01s runtime on modern CPU

    dest = (double*)aligned_alloc(32, n * sizeof(double));
    if (!dest) exit(1);

    b = (ringbuf*)malloc(sizeof(ringbuf));
    if (!b) exit(1);

    b->size = n;
    b->head = 0;
    b->tail = 0;

    b->array = (ringbuf_type_t*)aligned_alloc(32, b->size * sizeof(ringbuf_type_t));
    if (!b->array) exit(1);

    for (int j = 0; j < b->size; ++j) {
        b->array[j] = (ringbuf_type_t)(j & 65535) / 100.0;
    }

    for (int j = 0; j < n; ++j) {
        dest[j] = 0.0;
    }
}