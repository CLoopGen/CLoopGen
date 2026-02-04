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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing consecutive elements in cmn_mean and mfcp,
    // we traverse with a stride of 2 (process even indices first, then odd if needed).
    // Here we assume veclen is even for simplicity.
    for (f = 0; f < n_frame; f++) {
        mfcp = mfc[f];
        // Process elements with stride 2: even indices
        for (i = 0; i < veclen; i += 2)
            cmn_mean[i] += mfcp[i];
        // Process remaining odd indices
        for (i = 1; i < veclen; i += 2)
            cmn_mean[i] += mfcp[i];
    }
}
