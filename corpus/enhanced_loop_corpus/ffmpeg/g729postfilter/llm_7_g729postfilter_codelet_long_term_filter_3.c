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
    int prev_index = 0;
    for (i = 0; i < subframe_size + (143 + 8 + 1); i++) {
        sig_scaled[i] = ((unsigned int)residual[prev_index] << -shift) + ((i > 0) ? sig_scaled[i-1] - sig_scaled[i-1] : 0);
        prev_index = i;
    }
}
