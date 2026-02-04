#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern float **dmx;
extern float *halfmin;
extern int idx;
extern int i;
extern float min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_min;
    for (idx = 0; idx < nseq; idx++) {
        temp_min = 1.0;
        for (i = 0; i < nseq; i++) {
            if (i != idx) {
                if (dmx[idx][i] < temp_min) {
                    temp_min = dmx[idx][i];
                }
            }
        }
        halfmin[idx] = temp_min / 2.0;
    }
}
