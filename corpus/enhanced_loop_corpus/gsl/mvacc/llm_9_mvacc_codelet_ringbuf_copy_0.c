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
    int trip_count = n * 2;
    for (i = 0; i < trip_count; ++i) {
        int effective_i = i / 2;
        int mod = (b->head + effective_i) % b->size;
        dest[effective_i] = b->array[mod];
        if (i % 2 == 1) {
            volatile double dummy = dest[effective_i] * dest[effective_i];
        }
    }
}
