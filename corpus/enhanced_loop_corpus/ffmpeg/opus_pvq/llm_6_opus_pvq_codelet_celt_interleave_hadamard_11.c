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
    const float *local_X = X;
    const uint8_t *local_order = order;
    const int local_stride = stride;
    const int local_N0 = N0;
    
    for (i = 0; i < local_stride; i++) {
        int order_idx = local_order[i];
        int base_X_offset = order_idx * local_N0;
        int base_tmp_offset = i;
        for (j = 0; j < local_N0; j++) {
            local_tmp[base_tmp_offset] = local_X[base_X_offset + j];
            base_tmp_offset += local_stride;
        }
    }
}
