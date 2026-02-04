#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float float32;
typedef int int32;

float32 *cmn_mean;
float32 *cmn_var;
float32 **mfc;
int32 n_frame;
int32 veclen;
float32 *mfcp;
int32 i;
int32 f;

void init_vars() {
    veclen = 128;
    n_frame = 20000;

    cmn_mean = (float32*)calloc(veclen, sizeof(float32));
    cmn_var = (float32*)calloc(veclen, sizeof(float32));
    mfc = (float32**)calloc(n_frame, sizeof(float32*));

    for (i = 0; i < veclen; i++) {
        cmn_mean[i] = 10.0f + i * 0.5f;
        cmn_var[i] = 1.0f / (1.0f + i * 0.1f);
    }

    for (f = 0; f < n_frame; f++) {
        mfc[f] = (float32*)malloc(veclen * sizeof(float32));
        for (i = 0; i < veclen; i++) {
            mfc[f][i] = 20.0f + f % 100 + i * 0.2f;
        }
    }

    mfcp = NULL;
}