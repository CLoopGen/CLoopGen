#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef float INTFLOAT;

INTFLOAT g_decay_slope = 0.5f;
INTFLOAT a[3] = {1.0f, 2.0f, 3.0f};
INTFLOAT ag[3] = {0.0f, 0.0f, 0.0f};
int m = 0;

void init_vars() {
    g_decay_slope = 0.75f;
    a[0] = 10.0f;
    a[1] = 20.0f;
    a[2] = 30.0f;
    ag[0] = 0.0f;
    ag[1] = 0.0f;
    ag[2] = 0.0f;
    m = 0;
}