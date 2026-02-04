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
    for (j = 0; j < subframe_size + 152; j += 2) {
        sig_scaled[j] = residual[j] >> shift;
        if (j + 1 < subframe_size + 152) {
            sig_scaled[j + 1] = residual[j + 1] >> shift;
        }
    }
}
