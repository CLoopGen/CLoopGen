#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double mmacc_type_t;
typedef mmacc_type_t ringbuf_type_t;

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
    // Set problem size to achieve ~0.01 sec runtime
    // Assuming moderate CPU speed and memory bandwidth
    // Aim for about 32 million elements (~256 MB total data)
    n = 32 * 1024 * 1024 / sizeof(double);  // Adjust so dest is ~256MB when scaled by sizeof(double)
    n = (n > 1000000) ? 1000000 : n;         // Cap at 1M for safety
    n = (n < 10000) ? 10000 : n;             // Ensure minimum size

    // Allocate ring buffer structure
    b = (ringbuf*)malloc(sizeof(ringbuf));
    if (!b) exit(1);

    // Make sure ring buffer size is large enough to hold all accessed elements
    b->size = n + 1000;  // Larger than needed to ensure modulo arithmetic stays in bounds
    b->head = 500;       // Head offset so (head + i) < size for all i in [0, n)
    b->tail = 0;

    // Allocate arrays
    b->array = (ringbuf_type_t*)malloc(b->size * sizeof(ringbuf_type_t));
    dest = (double*)malloc(n * sizeof(double));

    if (!b->array || !dest) exit(1);

    // Initialize ring buffer data to avoid NaN or extreme values
    for (int j = 0; j < b->size; ++j) {
        b->array[j] = (ringbuf_type_t)(j & 0xFF);
    }

    // Initialize dest to zero
    for (int j = 0; j < n; ++j) {
        dest[j] = 0.0;
    }
}