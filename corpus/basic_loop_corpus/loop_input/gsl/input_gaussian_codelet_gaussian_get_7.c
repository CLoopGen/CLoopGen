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

typedef struct {
    size_t n;
    double *window;
    ringbuf *rbuf;
} gaussian_state_t;

gaussian_state_t *state;
double *kernel;
size_t n;
double sum;
size_t i;

static double *alloc_aligned_double_array(size_t count) {
    void *ptr;
    if (posix_memalign(&ptr, 32, count * sizeof(double)) != 0) {
        return NULL;
    }
    return (double *)ptr;
}

void init_vars() {
    n = 8 * 1024 * 1024 / sizeof(double);  // ~64MB total data target

    state = (gaussian_state_t *)calloc(1, sizeof(gaussian_state_t));
    kernel = alloc_aligned_double_array(n);
    state->window = alloc_aligned_double_array(n);
    state->rbuf = (ringbuf *)calloc(1, sizeof(ringbuf));

    state->n = n;
    state->rbuf->array = alloc_aligned_double_array(n);
    state->rbuf->size = n;

    for (size_t idx = 0; idx < n; ++idx) {
        state->window[idx] = 1.0 + idx * 0.0001;
        kernel[idx] = 1.0 - idx * 0.0001;
    }

    sum = 0.0;
    i = 0;
}