#include <stdlib.h>
#include <stdint.h>
#include <time.h>

double *vec;
int n;
int i;
double best;

void init_vars() {
    n = 32000000; // Approximately 256MB of data (32M * 8 bytes per double)
    vec = (double*)aligned_alloc(32, n * sizeof(double));
    
    // Initialize array with random values
    srand((unsigned int)time(NULL));
    for (int j = 0; j < n; j++) {
        vec[j] = (double)rand() / RAND_MAX * 1000.0;
    }

    // Initialize loop variables
    i = 0;
    best = vec[0]; // Ensure valid initial value
}