#include <stdio.h>

typedef long BLASLONG;

BLASLONG m;
float *b;
BLASLONG i;
float *a_offset;
float a1;
float a2;

#define DATA_SIZE (1 << 20)  // Approximately 1MB of float data

static float a_data[DATA_SIZE];
static float b_data[DATA_SIZE / 2];

void init_vars() {
    m = DATA_SIZE / 2;
    a_offset = a_data;
    b = b_data;
    a1 = 0.0f;
    a2 = 0.0f;
    
    for (BLASLONG j = 0; j < DATA_SIZE; j++) {
        a_data[j] = (float)(j % 128);
    }
}