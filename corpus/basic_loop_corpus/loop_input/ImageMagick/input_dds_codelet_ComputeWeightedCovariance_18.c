#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *covariance;
size_t i;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    covariance = (float *)calloc(data_size, sizeof(float));
    if (!covariance) {
        exit(1);
    }
}