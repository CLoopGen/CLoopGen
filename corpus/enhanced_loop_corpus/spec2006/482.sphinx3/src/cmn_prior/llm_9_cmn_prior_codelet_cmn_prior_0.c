#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 **incep;
extern int32 nfr;
extern int32 ceplen;
extern float32 *cur_mean;
extern float32 *sum;
extern int32 nframe;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nfr; i++) {
    for (j = 0; j < ceplen; j += 4) {
        sum[j]   += incep[i][j];
        incep[i][j]   -= cur_mean[j];
        if (j + 1 < ceplen) {
            sum[j+1] += incep[i][j+1];
            incep[i][j+1] -= cur_mean[j+1];
        }
        if (j + 2 < ceplen) {
            sum[j+2] += incep[i][j+2];
            incep[i][j+2] -= cur_mean[j+2];
        }
        if (j + 3 < ceplen) {
            sum[j+3] += incep[i][j+3];
            incep[i][j+3] -= cur_mean[j+3];
        }
    }
    ++nframe;
}
}
