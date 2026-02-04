#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern float32 **mfc;
extern int32 n_frame;
extern int32 veclen;
extern float32 *mfcp;
extern int32 i;
extern int32 f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (f = 0; f < n_frame; f++) {
        mfcp = mfc[f];
        for (i = veclen - 1; i >= 0; i--) {
            mfcp[i] -= cmn_mean[i];
        }
    }

    // Introduce artificial loop-carried dependence by using result of previous iteration
    if (n_frame > 0 && veclen > 0) {
        float32 accumulator = mfc[0][0];
        for (f = 1; f < n_frame; f++) {
            accumulator += mfc[f][0];
            mfc[f][0] = accumulator; // WAW and RAW dependency introduced across loop iterations
        }
    }
}
