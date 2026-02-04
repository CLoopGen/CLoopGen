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

    for (int j = 0; j < local_N0; j++) {
        for (int i = 0; i < local_stride; i++) {
            int write_idx = local_order[i] * local_N0 + j;
            int read_idx = j * local_stride + i;
            // Introduce artificial dependency: each write depends on previous iteration's value
            // This creates a WAW-like pattern if executed out of order, but remains correct sequentially
            local_tmp[write_idx] = local_X[read_idx] + (j > 0 ? local_tmp[write_idx - 1] * 0.0f : 0.0f);
        }
    }
}
