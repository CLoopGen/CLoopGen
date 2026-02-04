#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

float *vec;
int n;
float value;
int x;

void init_vars() {
    n = 67108864; // 67M elements * 4 bytes = ~256MB
    vec = (float*)calloc(n, sizeof(float));
    value = 3.14159f;
    x = 0;
}