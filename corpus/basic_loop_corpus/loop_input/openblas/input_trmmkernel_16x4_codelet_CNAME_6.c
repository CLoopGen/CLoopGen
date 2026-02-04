#include <stdio.h>

typedef long BLASLONG;

BLASLONG k;
float *ptrba;
float *ptrbb;
float res0_0;
float res1_0;
float a0;
float b0;
float b1;
BLASLONG temp;

static float array_a[65536];
static float array_b[131072];

void init_vars() {
    res0_0 = 0.0f;
    res1_0 = 0.0f;
    a0 = 0.0f;
    b0 = 0.0f;
    b1 = 0.0f;
    
    for (int i = 0; i < 65536; i++) {
        array_a[i] = 1.0f + (i % 7) * 0.1f;
    }
    
    for (int i = 0; i < 131072; i++) {
        array_b[i] = 1.5f + (i % 5) * 0.05f;
    }
    
    ptrba = array_a;
    ptrbb = array_b;
    temp = 65536;
}