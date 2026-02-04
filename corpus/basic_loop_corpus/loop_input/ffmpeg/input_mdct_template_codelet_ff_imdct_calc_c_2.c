#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float FFTSample;

FFTSample *output;
int k;
int n;
int n2;
int n4;

void init_vars() {
    n = 65536;          
    n2 = n / 2;         
    n4 = n / 4;         

    output = (FFTSample*)aligned_alloc(32, n * sizeof(FFTSample));
    if (!output) {
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        output[i] = (FFTSample)(i % 256);
    }
}

__attribute__((destructor))
void cleanup() {
    if (output) {
        free(output);
    }
}