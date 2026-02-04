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
    int outer_n = (n + 3) / 4;
    int j;
    for (j = 0; j < outer_n; ++j) {
        int idx0 = j * 4 + 0;
        int idx1 = j * 4 + 1;
        int idx2 = j * 4 + 2;
        int idx3 = j * 4 + 3;
        if (idx0 < n) dest[idx0] = b->array[(b->head + idx0) % b->size];
        if (idx1 < n) dest[idx1] = b->array[(b->head + idx1) % b->size];
        if (idx2 < n) dest[idx2] = b->array[(b->head + idx2) % b->size];
        if (idx3 < n) dest[idx3] = b->array[(b->head + idx3) % b->size];
    }
}
