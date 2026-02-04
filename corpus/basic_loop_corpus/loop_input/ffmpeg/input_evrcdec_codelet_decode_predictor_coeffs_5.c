#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

#define ILPC_SIZE 10

float *ilpc;
double lsp[10];
float a[6];
float b[6];
float a1[5];
float b1[5];
float a2[5];
float b2[5];
int i;
int k;

static float ilpc_data[ILPC_SIZE];

void init_vars() {
    ilpc = ilpc_data;
    
    for (int idx = 0; idx < 10; idx++) {
        lsp[idx] = 0.1 * idx;
    }
    
    for (int idx = 0; idx < 6; idx++) {
        a[idx] = 0.0f;
        b[idx] = 0.0f;
    }
    
    for (int idx = 0; idx < 5; idx++) {
        a1[idx] = 0.1f * idx;
        b1[idx] = 0.1f * idx;
        a2[idx] = 0.05f * idx;
        b2[idx] = 0.05f * idx;
    }
    
    i = 0;
    k = 0;
}