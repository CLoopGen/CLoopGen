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
    // Variant 2: Consecutive array traversal using pointer arithmetic without indexing
    for (f = 0; f < n_frame; f++) {
        float32 *ptr_mfcp = mfc[f];
        float32 *ptr_mean = cmn_mean;
        float32 *end = ptr_mfcp + veclen;
        while (ptr_mfcp < end) {
            *ptr_mfcp++ -= *ptr_mean++;
        }
    }
}
