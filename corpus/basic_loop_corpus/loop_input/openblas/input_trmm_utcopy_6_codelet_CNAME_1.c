#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;
float *ao5;
float *ao6;

#define BUFFER_SIZE (64 * 1024 * 1024 / sizeof(float)) // ~64 MB of float data
#define LOOP_COUNT (BUFFER_SIZE / 6)

static float b_buffer[BUFFER_SIZE];
static float ao1_buffer[BUFFER_SIZE];
static float ao2_buffer[BUFFER_SIZE];
static float ao3_buffer[BUFFER_SIZE];
static float ao4_buffer[BUFFER_SIZE];
static float ao5_buffer[BUFFER_SIZE];
static float ao6_buffer[BUFFER_SIZE];

void init_vars() {
    lda = 6; 
    i = LOOP_COUNT;
    ii = 0;

    b = b_buffer;
    ao1 = ao1_buffer;
    ao2 = ao2_buffer;
    ao3 = ao3_buffer;
    ao4 = ao4_buffer;
    ao5 = ao5_buffer;
    ao6 = ao6_buffer;

    for (int j = 0; j < BUFFER_SIZE; j++) {
        ao1_buffer[j] = 1.0f;
        ao2_buffer[j] = 2.0f;
        ao3_buffer[j] = 3.0f;
        ao4_buffer[j] = 4.0f;
        ao5_buffer[j] = 5.0f;
        ao6_buffer[j] = 6.0f;
        b_buffer[j] = 0.0f;
    }
}