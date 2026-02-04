#include <stdlib.h>
#include <stdint.h>

float *lut;
int N;
int n;

void init_vars() {
    N = 1 << 24; // Approximately 16.7 million elements
    lut = (float *)calloc(N, sizeof(float));
    if (!lut) {
        N = 0;
    }
}