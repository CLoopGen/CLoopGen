#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define SIZE (64 * 1024 * 1024) // ~256MB of float data

static float a_buffer[SIZE];
static float b_buffer[SIZE];

void init_vars() {
    lda = 8;
    a01 = a_buffer;
    b = b_buffer;

    for (int i = 0; i < SIZE; i++) {
        a_buffer[i] = (float)(i & 0xFF);
    }
}