#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef float INTFLOAT;

INTFLOAT g_decay_slope = 0.5f;

#define A_SIZE 1048576
INTFLOAT a[A_SIZE];

INTFLOAT ag[3];

int m;

void init_vars() {
    g_decay_slope = 0.75f;
    for (int i = 0; i < 3; i++) {
        ag[i] = 0.0f;
    }
    for (int i = 0; i < A_SIZE; i++) {
        a[i] = (INTFLOAT)(i % 100) + 1.0f;
    }
    m = 0;
}