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
    int mod_offset;
    for (i = 0; i < n * 2; i += 2) {
        mod_offset = (b->head + i/2) % b->size;
        dest[i/2] = b->array[mod_offset] * 1.5 + 0.1;
    }
}
