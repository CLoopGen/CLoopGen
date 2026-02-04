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

    for (j = 0; j < local_N0; j++) {
        for (i = 0; i < local_stride; i++) {
            int src_idx = local_order[i] * local_N0 + j;
            int dst_idx = j * local_stride + i;
            // Introduce temporary variable to create a write-after-write dependency elimination
            // and change data access pattern to column-major like in inner loop
            float val = local_X[src_idx];
            local_tmp[dst_idx] = val;
        }
    }
}
