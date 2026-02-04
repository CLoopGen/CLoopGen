#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *lwt;
extern float *rwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < nseq; i += 2) {
        if (i < nseq) {
            lwt[i] = rwt[i] = 0.;
        }
        if (i + 1 < nseq) {
            lwt[i + 1] = rwt[i + 1] = 0.;
        }
    }
}
