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

extern double *dest;
extern  ringbuf *b;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    snacc_type_t *dest_local = dest;
    ringbuf_type_t *array_local = b->array;
    int head_local = b->head;
    int size_local = b->size;
    for (i = 0; i < n; ++i) {
        dest_local[i] = array_local[(head_local + i) % size_local];
    }
}
