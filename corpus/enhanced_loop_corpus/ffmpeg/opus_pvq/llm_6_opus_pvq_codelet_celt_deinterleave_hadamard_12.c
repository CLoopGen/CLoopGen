#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *tmp;
extern float *X;
extern int N0;
extern int stride;
extern int i;
extern int j;
extern  uint8_t *order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_tmp = tmp;
    const int local_stride = stride;
    const int local_N0 = N0;
    const uint8_t *local_order = order;
    const float *local_X = X;

    for (int i = 0; i < local_stride; i++) {
        int base_idx = local_order[i] * local_N0;
        for (int j = 0; j < local_N0; j++) {
            local_tmp[base_idx + j] = local_X[j * local_stride + i];
        }
    }
}
