#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef int INTFLOAT;

INTFLOAT g_decay_slope = 15435;
INTFLOAT a[3] = {1000000, 2000000, 3000000};
INTFLOAT ag[3] = {0};
int m = 0;

void init_vars() {
    // Initialize variables to ensure correct behavior in loop
    g_decay_slope = 15435;
    a[0] = 1000000;
    a[1] = 2000000;
    a[2] = 3000000;
    ag[0] = ag[1] = ag[2] = 0;
    m = 0;
}