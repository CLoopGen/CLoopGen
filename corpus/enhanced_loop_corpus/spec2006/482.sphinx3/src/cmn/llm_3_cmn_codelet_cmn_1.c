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
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use an index remapping array to access cmn_mean and mfcp indirectly.
    // Simulate a permutation: reverse order access.
    // Assume we have a precomputed reverse index map, but generate it on the fly conceptually.
    int32 idx;
    for (f = 0; f < n_frame; f++) {
        mfcp = mfc[f];
        for (i = 0; i < veclen; i++) {
            idx = veclen - 1 - i;  // reverse mapping: last element first
            cmn_mean[idx] += mfcp[idx];
        }
    }
}
