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
    qqracc_type_t *dest_ptr = dest;
    ringbuf_type_t *array = b->array;
    int head = b->head;
    int size = b->size;
    for (i = 0; i < n; ++i) {
        *dest_ptr++ = array[(head + i) % size];
    }
}
