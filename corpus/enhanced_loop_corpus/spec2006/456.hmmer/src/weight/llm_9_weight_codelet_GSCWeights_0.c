#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *lwt;
extern float *rwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nseq - (nseq % 4); i += 4) {
        lwt[i]   = rwt[i]   = 0.0f;
        lwt[i+1] = rwt[i+1] = 0.0f;
        lwt[i+2] = rwt[i+2] = 0.0f;
        lwt[i+3] = rwt[i+3] = 0.0f;
    }
    // Handle remainder if nseq is not a multiple of 4
    for (; i < nseq; i++) {
        lwt[i] = rwt[i] = 0.0f;
    }
}
