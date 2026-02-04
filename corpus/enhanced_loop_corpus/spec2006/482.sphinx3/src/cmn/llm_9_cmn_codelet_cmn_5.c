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
extern float32 t;
extern int32 i;
extern int32 f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (f = 0; f < n_frame; f++) {
    mfcp = mfc[f];
    for (i = 0; i < veclen; i += 4) {
        float32 t0 = mfcp[i]   - cmn_mean[i];
        float32 t1 = mfcp[i+1] - cmn_mean[i+1];
        float32 t2 = mfcp[i+2] - cmn_mean[i+2];
        float32 t3 = mfcp[i+3] - cmn_mean[i+3];
        cmn_var[i]   += t0 * t0;
        cmn_var[i+1] += t1 * t1;
        cmn_var[i+2] += t2 * t2;
        cmn_var[i+3] += t3 * t3;
    }
}
}
