#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *residual;
extern int subframe_size;
extern int i;
extern int16_t shift;
extern int16_t sig_scaled[192];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    int trip_count = (subframe_size + 152) * 2;
    for (j = 0; j < trip_count; j += 2) {
        int idx = j / 2;
        sig_scaled[idx] = (residual[idx] >> shift) + (residual[idx] > 0 ? 1 : 0);
    }
}
