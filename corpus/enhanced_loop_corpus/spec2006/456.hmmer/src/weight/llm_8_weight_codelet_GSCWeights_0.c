#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *lwt;
extern float *rwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < nseq; i++) {
        lwt[i] = rwt[i] = 0.;
        for (j = 1; j < 4; j++) {
            lwt[i] += (float)(j * j);
            rwt[i] -= (float)(j);
        }
    }
}
