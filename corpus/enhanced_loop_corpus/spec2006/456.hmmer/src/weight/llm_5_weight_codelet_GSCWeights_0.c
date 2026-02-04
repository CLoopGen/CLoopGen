#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *lwt;
extern float *rwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nseq; i++) {
    lwt[i] = 0.;
    if (1) {
        rwt[i] = 0.;
    }
}
}
