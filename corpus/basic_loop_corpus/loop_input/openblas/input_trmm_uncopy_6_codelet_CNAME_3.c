#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;

static float b_array[65536];
static float ao1_array[65536];
static float ao2_array[65536];
static float ao3_array[65536];
static float ao4_array[65536];

void init_vars() {
    b = b_array;
    ao1 = ao1_array;
    ao2 = ao2_array;
    ao3 = ao3_array;
    ao4 = ao4_array;
    i = 16384;
}