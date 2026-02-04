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
        i = 0;
        for (; i < veclen; i += 2) {
            if (i + 1 < veclen) {
                mfcp[i]     = (mfcp[i]     - cmn_mean[i])     * cmn_var[i];
                mfcp[i + 1] = (mfcp[i + 1] - cmn_mean[i + 1]) * cmn_var[i + 1];
            } else {
                mfcp[i] = (mfcp[i] - cmn_mean[i]) * cmn_var[i];
            }
        }
    }
}
