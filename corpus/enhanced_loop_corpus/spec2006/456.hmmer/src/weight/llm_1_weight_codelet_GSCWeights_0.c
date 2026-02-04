#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *lwt;
extern float *rwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nseq; i += 2) {
        lwt[i] = rwt[i] = 0.;
        if (i + 1 < nseq) {
            lwt[i + 1] = rwt[i + 1] = 0.;
        }
    }
}
