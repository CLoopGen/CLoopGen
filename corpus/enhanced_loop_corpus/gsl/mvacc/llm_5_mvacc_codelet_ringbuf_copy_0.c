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
    for (i = 0; i < n && b->head < b->size; ++i) {
        int idx = b->head + i;
        dest[i] = (idx < b->size) ? b->array[idx] : b->array[idx % b->size];
    }
}
