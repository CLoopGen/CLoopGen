#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 **incep;
extern int32 nfr;
extern int32 ceplen;
extern float32 *cur_mean;
extern float32 *sum;
extern int32 nframe;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Introduce an index array to access elements in non-sequential order
    // Simulate indirect access: process elements from end to start using reverse indexing
    int32 *idx = (int32*)__builtin_alloca(ceplen * sizeof(int32));
    for (int32 k = 0; k < ceplen; k++) {
        idx[k] = ceplen - 1 - k; // Reverse order indices
    }
    for (i = 0; i < nfr; i++) {
        for (int32 k = 0; k < ceplen; k++) {
            int32 j = idx[k]; // Indirect access through index mapping
            sum[j] += incep[i][j];
            incep[i][j] -= cur_mean[j];
        }
        ++nframe;
    }
}
