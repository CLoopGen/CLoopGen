#include <stdio.h>

typedef long BLASLONG;

float *x;
float *y;
BLASLONG i;
float dot;
int n1;

#define ARRAY_SIZE 65536000  // ~250 MB for two float arrays (each float is 4 bytes)

static float x_data[ARRAY_SIZE];
static float y_data[ARRAY_SIZE];

void init_vars() {
    x = x_data;
    y = y_data;
    i = 0;
    dot = 0.0f;
    n1 = ARRAY_SIZE - (ARRAY_SIZE % 4);  // Ensure n1 is multiple of 4 to avoid out-of-bounds access

    for (BLASLONG j = 0; j < n1; j++) {
        x[j] = 1.0f + (j % 100) * 0.01f;
        y[j] = 2.0f + (j % 150) * 0.02f;
    }
}