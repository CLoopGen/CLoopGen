#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float *wgt;
extern float *fwt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < nseq; i++)
            wgt[i] = fwt[i];
}
