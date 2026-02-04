#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int rows;
int cols;
float **mx;
int r;

void init_vars() {
    rows = 65536;
    cols = 32;
    mx = (float**)calloc(rows, sizeof(float*));
    if (!mx) exit(1);
    float *data = (float*)calloc(rows * cols, sizeof(float));
    if (!data) exit(1);
    for (int i = 0; i < rows; i++) {
        mx[i] = data + i * cols;
    }
}