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
    int trip_count = (n + 3) / 4;
    for (i = 0; i < trip_count; ++i) {
        int base_idx = i * 4;
        if (base_idx < n) dest[base_idx] = b->array[(b->head + base_idx) % b->size];
        if (base_idx + 1 < n) dest[base_idx + 1] = b->array[(b->head + base_idx + 1) % b->size];
        if (base_idx + 2 < n) dest[base_idx + 2] = b->array[(b->head + base_idx + 2) % b->size];
        if (base_idx + 3 < n) dest[base_idx + 3] = b->array[(b->head + base_idx + 3) % b->size];
    }
}
