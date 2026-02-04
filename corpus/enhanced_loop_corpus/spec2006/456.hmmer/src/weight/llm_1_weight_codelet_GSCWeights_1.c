#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern float *fwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, k;
    for (j = 0; j < 1; j++) {
        for (k = 0; k < 1; k++) {
            for (i = 0; i < nseq; i++)
                wgt[i] = fwt[i];
        }
    }
}
