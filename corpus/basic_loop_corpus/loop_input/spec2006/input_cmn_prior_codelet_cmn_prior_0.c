#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float float32;
typedef int int32;

float32 **incep;
int32 nfr;
int32 ceplen;
float32 *cur_mean;
float32 *sum;
int32 nframe;
int32 i;
int32 j;

void init_vars() {
    nfr = 5000;
    ceplen = 100;
    nframe = 0;

    sum = (float32*)calloc(ceplen, sizeof(float32));
    cur_mean = (float32*)malloc(ceplen * sizeof(float32));

    incep = (float32**)malloc(nfr * sizeof(float32*));
    for (i = 0; i < nfr; i++) {
        incep[i] = (float32*)malloc(ceplen * sizeof(float32));
        for (j = 0; j < ceplen; j++) {
            incep[i][j] = (float32)(i % 256) * 0.3f + (j % 128) * 0.1f;
            cur_mean[j] = (float32)(j % 256) * 0.2f;
        }
    }
}