#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *lwt;
extern float *rwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = 0; k < nseq; k += 2) {
        if (k + 1 < nseq) {
            lwt[k] = 0.;           // Remove potential WAW by accessing non-overlapping indices
            rwt[k] = 0.;
            lwt[k+1] = 0.;         // No loop-carried dependency; independent per iteration
            rwt[k+1] = 0.;
        }
    }
    // Handle odd nseq
    if (nseq % 2 == 1) {
        lwt[nseq-1] = 0.;
        rwt[nseq-1] = 0.;
    }
}
