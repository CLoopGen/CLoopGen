#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned long buffer[56];
} ran3_state_t;

extern ran3_state_t *state;
extern int i;
extern long j;
extern long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access the buffer with a fixed stride (e.g., stride of 2), wrapping around using modulo.
    // This creates a non-uniform but deterministic access pattern, still covering most indices.
    const int stride = 2;
    int n = 1;  // Starting index
    for (i = 1; i < 55; i++) {
        n = (n + stride) % 55;
        state->buffer[n] = k;
        k = j - k;
        if (k < 0)
            k += 1000000000;
        j = state->buffer[n];
    }
}
