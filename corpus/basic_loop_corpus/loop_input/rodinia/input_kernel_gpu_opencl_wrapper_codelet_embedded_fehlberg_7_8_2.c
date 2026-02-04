#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

// External variable declarations
float h;
float *initvalu;
float b31;
float b32;
float *initvalu_temp;
float **finavalu_temp;
int i;

// Define array sizes
#define N 91
#define DATA_SIZE (1 << 20) // ~1MB of data per float array

// Allocate sufficient memory to make loop take ~0.01s
// We'll allocate multiple copies to increase working set

static float initvalu_data[DATA_SIZE / sizeof(float)];
static float initvalu_temp_data[DATA_SIZE / sizeof(float)];

// Two rows for finavalu_temp
static float finavalu_row1[DATA_SIZE / sizeof(float)];
static float finavalu_row2[DATA_SIZE / sizeof(float)];
static float *finavalu_pointers[2];

void init_vars() {
    // Initialize scalar values
    h = 0.001f;
    b31 = 0.5f;
    b32 = 0.5f;
    i = 0;

    // Seed random number generator for realistic initialization
    srand(time(NULL));

    // Initialize input arrays with meaningful data
    for (int j = 0; j < N; j++) {
        initvalu_data[j] = ((float)rand()) / RAND_MAX;
        initvalu_temp_data[j] = 0.0f;
        finavalu_row1[j] = ((float)rand()) / RAND_MAX;
        finavalu_row2[j] = ((float)rand()) / RAND_MAX;
    }

    // Initialize pointer arrays
    initvalu = initvalu_data;
    initvalu_temp = initvalu_temp_data;
    finavalu_pointers[0] = finavalu_row1;
    finavalu_pointers[1] = finavalu_row2;
    finavalu_temp = finavalu_pointers;
}