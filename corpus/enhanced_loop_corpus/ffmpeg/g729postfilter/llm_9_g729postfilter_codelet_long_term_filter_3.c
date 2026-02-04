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
    int step = 2;
    int limit = (subframe_size + (143 + 8 + 1)) / 2;
    for (i = 0; i < limit; i += step) {
        sig_scaled[2*i]     = (unsigned int)residual[2*i]     << -shift;
        if (2*i + 1 < subframe_size + (143 + 8 + 1)) {
            sig_scaled[2*i + 1] = (unsigned int)residual[2*i + 1] << -shift;
        }
    }
}
