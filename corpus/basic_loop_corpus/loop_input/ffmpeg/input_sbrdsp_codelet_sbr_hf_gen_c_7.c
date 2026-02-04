#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define DATA_SIZE (64 << 10)

float (*X_high)[2];
float (*X_low)[2];
int start;
int end;
float alpha[4];
int i;

void init_vars() {
    X_low = malloc(DATA_SIZE * sizeof(float[2]));
    X_high = malloc(DATA_SIZE * sizeof(float[2]));

    start = 2;
    end = DATA_SIZE - 1;

    alpha[0] = sinf(0.1f);
    alpha[1] = cosf(0.1f);
    alpha[2] = sinf(0.2f);
    alpha[3] = cosf(0.2f);

    for (int idx = 0; idx < DATA_SIZE; idx++) {
        X_low[idx][0] = (float)(idx % 100) * 0.01f;
        X_low[idx][1] = (float)(idx % 75) * 0.02f;
        X_high[idx][0] = 0.0f;
        X_high[idx][1] = 0.0f;
    }
}