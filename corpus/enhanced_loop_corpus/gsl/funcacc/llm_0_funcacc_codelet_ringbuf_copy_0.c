#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double funcacc_type_t;

typedef funcacc_type_t ringbuf_type_t;

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
    int j, k;
    for (j = 0; j < n; ++j) {
        for (k = 0; k < 1; ++k)
            dest[j] = b->array[(b->head + j) % b->size];
    }
}
