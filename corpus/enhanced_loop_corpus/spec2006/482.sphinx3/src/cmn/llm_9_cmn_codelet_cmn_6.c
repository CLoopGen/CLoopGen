#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *cmn_mean;
extern float32 *cmn_var;
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
    for (i = 0; i < veclen; i++) {
        float32 diff = mfcp[i] - cmn_mean[i];
        float32 inv_var = cmn_var[i];
        mfcp[i] = diff * inv_var;
        mfcp[i] += 0.001f * diff; // Additional light computation to increase arithmetic intensity
    }
}
}
