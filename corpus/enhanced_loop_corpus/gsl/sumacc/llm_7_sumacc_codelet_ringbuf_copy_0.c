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

extern double *dest;
extern  ringbuf *b;
extern  int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *local_dest = dest;
    ringbuf_type_t *local_array = b->array;
    int head = b->head;
    int size = b->size;
    double prev = 0.0;
    for (i = 0; i < n; ++i) {
        double curr = local_array[(head + i) % size];
        local_dest[i] = curr + prev;
        prev = curr;
    }
}
