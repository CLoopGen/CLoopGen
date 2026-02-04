#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

extern int32 ceplen;
extern float32 *sum;
extern float32 sf;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    float32 local_sf = sf;  // Eliminate potential aliasing, break external dependencies
    #pragma unroll
    for (j = 0; j < ceplen; j++) {
        float32 val = sum[j];
        val *= local_sf;    // Remove direct write-back dependency (no WAW or WAR on sum[i])
        sum[j] = val;       // Independent update, but still updates same memory (no loop-carried dep)
    }
}
