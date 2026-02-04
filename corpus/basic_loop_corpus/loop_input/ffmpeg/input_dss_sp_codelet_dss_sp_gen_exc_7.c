#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *vector;
int32_t *prev_exc;
int pitch_lag;
int i;

#define DATA_SIZE (64 * 1024 * 1024) // ~256MB of data (64M int32_t elements)

static int32_t vector_buffer[DATA_SIZE];
static int32_t prev_exc_buffer[DATA_SIZE];

void init_vars() {
    vector = vector_buffer;
    prev_exc = prev_exc_buffer;
    pitch_lag = 71; // Ensures that pitch_lag - i >= 0 when i=0,...,71
    
    // Initialize buffers to zero (or any valid int32_t value)
    for (int j = 0; j < DATA_SIZE; j++) {
        vector_buffer[j] = 0;
        prev_exc_buffer[j] = rand() % 1000;
    }
}