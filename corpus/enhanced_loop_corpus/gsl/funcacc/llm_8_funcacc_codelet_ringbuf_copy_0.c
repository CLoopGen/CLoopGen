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
    int j;
    for (i = 0; i < n; i += 2) {
        j = (b->head + i) % b->size;
        dest[i] = b->array[j];
        if (i + 1 < n) {
            dest[i + 1] = b->array[(j + 1) % b->size];
        }
    }
}
