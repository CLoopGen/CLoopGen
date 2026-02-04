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
    int stride = 2;
    for (i = 0; i < n; i += stride) {
        dest[n - i - 1] = b->array[(b->head + i) % b->size];
        if (i + 1 < n)
            dest[n - (i + 1) - 1] = b->array[(b->head + i + 1) % b->size];
    }
}
