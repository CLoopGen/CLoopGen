#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
    veclen = 128;
    n_frame = 20000;

    cmn_mean = (float32*)calloc(veclen, sizeof(float32));
    mfc = (float32**)malloc(n_frame * sizeof(float32*));

    for (int32 frame_idx = 0; frame_idx < n_frame; frame_idx++) {
        float32* frame_data = (float32*)malloc(veclen * sizeof(float32));
        for (int32 vec_idx = 0; vec_idx < veclen; vec_idx++) {
            frame_data[vec_idx] = (float32)(frame_idx + vec_idx) / (veclen + 1);
        }
        mfc[frame_idx] = frame_data;
    }

    mfcp = NULL;
    i = 0;
    f = 0;
}