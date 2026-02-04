#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double qnacc_type_t;
typedef qnacc_type_t ringbuf_type_t;

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
    // Set data size to achieve ~0.01 seconds runtime
    // For typical modern CPU, 64M doubles ≈ 512 MB, which should be in the target range
    n = 64 * 1024 * 1024;  // 64 million elements

    // Allocate destination array
    dest = (double*)aligned_alloc(32, n * sizeof(double));
    if (!dest) exit(1);

    // Initialize ring buffer
    b = (ringbuf*)aligned_alloc(32, sizeof(ringbuf));
    if (!b) exit(1);

    // Use a reasonable ring buffer size - make it large enough to avoid modulo being trivial
    b->size = 1024 * 1024;  // 1M element ring buffer
    b->array = (ringbuf_type_t*)aligned_alloc(32, b->size * sizeof(ringbuf_type_t));
    if (!b->array) exit(1);

    // Initialize head to a valid position within [0, size)
    b->head = 123456;  // Arbitrary offset
    b->tail = (b->head + n - 1) % b->size;  // Ensure tail is consistent with n elements

    // Initialize all arrays with non-zero values to avoid accidental optimization
    for (int j = 0; j < b->size; ++j) {
        b->array[j] = (ringbuf_type_t)(j * 0.5 + 1.0);
    }
    for (int j = 0; j < n; ++j) {
        dest[j] = 0.0;
    }
}