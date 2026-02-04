#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int m;
double *result_array;
int j;

void init_vars() {
    m = 13421772;  // Approximately 100 million iterations for ~0.01 sec on modern CPU (13421772 * sizeof(double) ≈ 107 MB)
    result_array = (double*)calloc(m, sizeof(double));
    j = 0;
}

void loop();

// Ensure the loop function can be called from elsewhere and uses the defined variables