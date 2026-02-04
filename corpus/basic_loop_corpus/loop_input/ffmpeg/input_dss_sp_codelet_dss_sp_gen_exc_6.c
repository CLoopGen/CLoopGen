#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define VECTOR_SIZE 72
#define DATA_SIZE (1 << 20) // 1MB of data for timing (~0.01 sec on modern CPU)

int32_t *vector;
int32_t *prev_exc;
int pitch_lag;
int i;

static int32_t vector_data[VECTOR_SIZE];
static int32_t prev_exc_data[DATA_SIZE];

void init_vars() {
    vector = vector_data;
    prev_exc = prev_exc_data;
    pitch_lag = 40; // Ensures pitch_lag - i % pitch_lag stays within bounds for i in [0,71]
    
    // Initialize arrays with non-zero values to simulate realistic data
    for (int j = 0; j < VECTOR_SIZE; j++) {
        vector_data[j] = 0;
    }
    for (int j = 0; j < DATA_SIZE; j++) {
        prev_exc_data[j] = rand() % 1000;
    }
}