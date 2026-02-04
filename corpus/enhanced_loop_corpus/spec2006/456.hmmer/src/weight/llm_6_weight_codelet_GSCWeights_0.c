#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *lwt;
extern float *rwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < nseq; j++) {
        lwt[j] = 0.;
        rwt[j] = lwt[j]; // Introduce RAW dependency: rwt[j] depends on lwt[j]
    }
}
