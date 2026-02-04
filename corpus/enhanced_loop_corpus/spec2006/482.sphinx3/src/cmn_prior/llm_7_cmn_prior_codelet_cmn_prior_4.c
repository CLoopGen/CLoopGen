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
    float32 local_sf = sf;
    for (i = 0; i < ceplen; i += 2) {
        if (i + 1 < ceplen) {
            sum[i] *= local_sf;     // Eliminate loop-carried dependency by enabling potential parallel updates
            sum[i+1] *= local_sf;   // No dependency between sum[i] and sum[i+1] updates
        } else {
            sum[i] *= local_sf;
        }
    }
}
