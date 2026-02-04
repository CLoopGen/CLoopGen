#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double qqracc_type_t;

typedef qqracc_type_t ringbuf_type_t;

typedef struct {
    ringbuf_type_t *array;
    int head;
    int tail;
    int size;
} ringbuf;

extern double *dest;
extern  ringbuf *b;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write but reverse-order read from ring buffer
    for (i = 0; i < n; ++i) {
        int read_index = (b->head + b->size - 1 - i) % b->size;
        dest[i] = b->array[read_index];
    }
}
