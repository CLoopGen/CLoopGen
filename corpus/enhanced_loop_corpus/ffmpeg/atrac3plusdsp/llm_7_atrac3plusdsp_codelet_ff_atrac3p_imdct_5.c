#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *pIn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *restrict local_pIn = pIn;
    for (i = 0; i < 64; i += 2) {
        float temp_i0 = local_pIn[i];
        float temp_i1 = local_pIn[i + 1];
        int j0 = 127 - i;
        int j1 = 126 - i;
        float temp_j0 = local_pIn[j0];
        float temp_j1 = local_pIn[j1];
        local_pIn[i] = temp_j0;
        local_pIn[i + 1] = temp_j1;
        local_pIn[j0] = temp_i0;
        local_pIn[j1] = temp_i1;
    }
    if (i == 126) {
        int mid = 63;
        float swap_tmp = local_pIn[mid];
        local_pIn[mid] = local_pIn[64];
        local_pIn[64] = swap_tmp;
    }
}
