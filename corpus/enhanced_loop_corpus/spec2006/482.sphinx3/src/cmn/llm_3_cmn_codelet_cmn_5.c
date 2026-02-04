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
    // Variant 2: Indirect memory access via index mapping array
    // Simulate indirect access using a fixed permutation (e.g., reverse order)
    int32 idx;
    for (f = 0; f < n_frame; f++) {
        mfcp = mfc[f];
        for (i = 0; i < veclen; i++) {
            // Access elements in reverse order: map i -> veclen - 1 - i
            idx = veclen - 1 - i;
            t = mfcp[idx] - cmn_mean[idx];
            cmn_var[idx] += t * t;
        }
    }
}
