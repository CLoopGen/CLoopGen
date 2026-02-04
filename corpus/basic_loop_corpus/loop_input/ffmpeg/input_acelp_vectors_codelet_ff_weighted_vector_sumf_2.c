#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *out;
float *in_a;
float *in_b;
float weight_coeff_a;
float weight_coeff_b;
int length;
int i;

void init_vars() {
    length = 65536 * 4;  // ~1MB of float data (each array has 262144 floats, total ~3.14MB)
    
    in_a = (float*)malloc(length * sizeof(float));
    in_b = (float*)malloc(length * sizeof(float));
    out = (float*)malloc(length * sizeof(float));

    weight_coeff_a = 0.4f;
    weight_coeff_b = 0.6f;

    for (int j = 0; j < length; j++) {
        in_a[j] = (float)(j % 100) * 0.01f;
        in_b[j] = (float)(j % 200) * 0.02f;
    }
}