#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float synthesis_low[7];
float *output;
float *temp;
int i;
int findex;

void init_vars() {
    findex = 1000000;
    int temp_size = findex + 11;
    int output_size = 2 * (findex + 10) - 7 + 1;

    temp = (float*)calloc(temp_size, sizeof(float));
    output = (float*)calloc(output_size, sizeof(float));

    for (int j = 0; j < 7; j++) {
        synthesis_low[j] = 1.0f / (j + 1);
    }

    for (int j = 9; j < temp_size; j++) {
        temp[j] = (float)(j % 1000) / 100.0f;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}