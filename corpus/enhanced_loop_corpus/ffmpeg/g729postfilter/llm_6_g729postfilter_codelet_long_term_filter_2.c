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
    for (j = 0; j < subframe_size + (143 + 8 + 1); j++) {
        sig_scaled[j] = residual[j] >> shift;
        if (j > 0) {
            sig_scaled[j] += sig_scaled[j - 1] & 0x1; // Introduce RAW dependency: current iteration uses previous output
        }
    }
}
