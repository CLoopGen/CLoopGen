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
float32 local_sum[ceplen];
for (j = 0; j < ceplen; j++) {
    local_sum[j] = 0.0f;
}
for (i = 0; i < nfr; i++) {
    for (j = 0; j < ceplen; j++) {
        local_sum[j] += incep[i][j];
        incep[i][j] -= cur_mean[j];
    }
}
for (j = 0; j < ceplen; j++) {
    sum[j] += local_sum[j];
}
nframe += nfr;
}
