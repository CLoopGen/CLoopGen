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
    for (i = 0; i < subframe_size + (143 + 8 + 1); i++) {
        if (i % 2 == 0) {
            sig_scaled[i] = residual[i] >> shift;
        } else {
            sig_scaled[i] = residual[i] >> shift;
        }
    }
}
