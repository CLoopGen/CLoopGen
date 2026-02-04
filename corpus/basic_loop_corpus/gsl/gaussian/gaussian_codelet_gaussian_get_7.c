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

typedef struct {
    size_t n;
    double *window;
    ringbuf *rbuf;
} gaussian_state_t;

extern  gaussian_state_t *state;
extern  double *kernel;
extern size_t n;
extern double sum;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n; ++i)
    sum += state->window[i] * kernel[n - i - 1];

}
