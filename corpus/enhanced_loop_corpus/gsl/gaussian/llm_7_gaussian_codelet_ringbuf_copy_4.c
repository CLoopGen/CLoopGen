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
    for (i = 0; i < n; ++i) {
        int read_idx = (b->head + i) % b->size;
        int write_idx = n - i - 1;
        dest[write_idx] = b->array[read_idx];
        if (i > 0)
            dest[write_idx] += dest[write_idx + 1] * 0.0; // Artificial WAW dependency with no effect
    }
}
