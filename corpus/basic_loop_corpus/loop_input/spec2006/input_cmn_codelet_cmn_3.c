#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef float float32;
typedef int int32;

float32 *cmn_mean;
float32 **mfc;
int32 n_frame;
int32 veclen;
float32 *mfcp;
int32 i;
int32 f;

void init_vars() {
    veclen = 13;
    n_frame = 20000;

    cmn_mean = (float32*)calloc(veclen, sizeof(float32));
    mfc = (float32**)calloc(n_frame, sizeof(float32*));

    for (int32 frame = 0; frame < n_frame; frame++) {
        mfc[frame] = (float32*)malloc(veclen * sizeof(float32));
        for (int32 j = 0; j < veclen; j++) {
            mfc[frame][j] = (float32)(frame + j);
        }
    }

    for (int32 j = 0; j < veclen; j++) {
        cmn_mean[j] = (float32)(j * 0.5f);
    }

    mfcp = NULL;
    i = 0;
    f = 0;
}