#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *lwt;
extern float *rwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = nseq - 1; i >= 0; i--) {
        lwt[i] = rwt[i] = 0.;
    }
}
