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
    // Variant 1: Strided Memory Access Pattern
    // Instead of processing each frame sequentially with unit stride, access every 2nd frame (stride of 2),
    // and process frames in two passes: even-indexed and odd-indexed.
    // This modifies spatial locality and access pattern while preserving correctness.

    // First pass: even frame indices
    for (f = 0; f < n_frame; f += 2) {
        mfcp = mfc[f];
        for (i = 0; i < veclen; i++)
            mfcp[i] = (mfcp[i] - cmn_mean[i]) * cmn_var[i];
    }
    // Second pass: odd frame indices
    for (f = 1; f < n_frame; f += 2) {
        mfcp = mfc[f];
        for (i = 0; i < veclen; i++)
            mfcp[i] = (mfcp[i] - cmn_mean[i]) * cmn_var[i];
    }
}
