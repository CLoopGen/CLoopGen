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
    // Variant 1: Strided memory access pattern
    // Instead of accessing consecutive elements in order, access them with a stride of 2, then handle remainder
    for (f = 0; f < n_frame; f++) {
        mfcp = mfc[f];
        // First pass: even indices
        for (i = 0; i < veclen; i += 2) {
            t = mfcp[i] - cmn_mean[i];
            cmn_var[i] += t * t;
        }
        // Second pass: odd indices
        for (i = 1; i < veclen; i += 2) {
            t = mfcp[i] - cmn_mean[i];
            cmn_var[i] += t * t;
        }
    }
}
