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
    float32 *local_mean = cmn_mean;
    float32 **local_mfc = mfc;
    int32 local_n_frame = n_frame;
    int32 local_veclen = veclen;

    for (f = 0; f < local_n_frame; f++) {
        mfcp = local_mfc[f];
        for (i = 0; i < local_veclen; i++) {
            mfcp[i] = mfcp[i] - local_mean[i];
        }
    }
}
