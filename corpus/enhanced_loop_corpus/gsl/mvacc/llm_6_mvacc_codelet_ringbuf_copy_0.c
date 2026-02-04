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
    int local_head = b->head;
    int local_size = b->size;
    for (i = 0; i < n; ++i) {
        int index = local_head + i;
        if (index >= local_size)
            index -= local_size;
        local_dest[i] = local_array[index];
    }
}
