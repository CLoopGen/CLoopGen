#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef double madacc_type_t;
typedef madacc_type_t ringbuf_type_t;

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
    // Set data size to achieve ~0.01 sec runtime
    // Estimate: ~100 million iterations for 0.01s on modern CPU
    n = 262144;  // ~2MB of output (262144 * sizeof(double) ≈ 2.1MB)
    
    // Allocate destination array
    dest = (double*)aligned_alloc(32, n * sizeof(double));
    
    // Initialize ring buffer structure
    b = (ringbuf*)malloc(sizeof(ringbuf));
    b->size = n;  // Ensure ring buffer is at least as large as needed
    b->head = 0;
    b->tail = 0;
    
    // Allocate ring buffer array
    b->array = (ringbuf_type_t*)aligned_alloc(32, b->size * sizeof(ringbuf_type_t));
    
    // Initialize ring buffer contents
    for (int j = 0; j < b->size; ++j) {
        b->array[j] = (ringbuf_type_t)(j * 1.5);
    }
    
    // Ensure head + i < head + n <= size so modulo indexing stays valid
    // With head=0 and size=n, we are safe for all i in [0, n-1]
}

// External variables must be defined at file scope
double *dest;
ringbuf *b;
int n;
int i;