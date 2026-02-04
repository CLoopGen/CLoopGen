#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>

typedef float float32;
typedef int int32;

float32 *cmn_mean;
float32 *cmn_var;
float32 **mfc;
int32 n_frame;
int32 veclen;
float32 *mfcp;
float32 t;
int32 i;
int32 f;

void init_vars() {
    veclen = 128;
    n_frame = 20000;

    cmn_mean = (float32*)calloc(veclen, sizeof(float32));
    cmn_var = (float32*)calloc(veclen, sizeof(float32));
    mfc = (float32**)malloc(n_frame * sizeof(float32*));

    for (int32 frame = 0; frame < n_frame; frame++) {
        float32* vec = (float32*)malloc(veclen * sizeof(float32));
        for (int32 idx = 0; idx < veclen; idx++) {
            vec[idx] = (float32)(frame + idx);
            cmn_mean[idx] = (float32)idx;
        }
        mfc[frame] = vec;
    }

    mfcp = NULL;
    t = 0.0f;
    i = 0;
    f = 0;
}