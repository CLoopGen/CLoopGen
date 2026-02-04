#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;

static float b_buffer[262144]; // 1MB of float data (262144 elements)
static float ao1_buffer[4] = {1.0f, 2.0f, 3.0f, 4.0f}; // ao1 needs only 4 elements

void init_vars() {
    i = 65536; // Each iteration processes 4 floats, so total size is i * 4 = 262144
    b = b_buffer;
    ao1 = ao1_buffer;
}