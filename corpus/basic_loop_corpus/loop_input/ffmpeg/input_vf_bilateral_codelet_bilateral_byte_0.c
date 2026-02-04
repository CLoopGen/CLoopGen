#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int width;
float *map_factor_b;
float *ypf;
int h1;

void init_vars() {
    width = 32768; 
    h1 = 10;

    map_factor_b = (float *)aligned_alloc(32, sizeof(float) * width * (h1 + 1));
    ypf = (float *)aligned_alloc(32, sizeof(float) * width);

    for (int i = 0; i < width * (h1 + 1); i++) {
        map_factor_b[i] = 1.0F * (i % 100);
    }
    for (int i = 0; i < width; i++) {
        ypf[i] = 2.0F * (i % 50);
    }
}