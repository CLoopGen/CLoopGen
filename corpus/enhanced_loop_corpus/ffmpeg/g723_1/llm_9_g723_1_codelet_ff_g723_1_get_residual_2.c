#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *residual;
extern int16_t *prev_excitation;
extern int lag;
extern int offset;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 30; i += 3) {
        int idx1 = offset + (i - 2) % lag;
        int idx2 = offset + (i - 1) % lag;
        int idx3 = offset + (i) % lag;
        residual[i]     = prev_excitation[idx1];
        residual[i + 1] = prev_excitation[idx2];
        residual[i + 2] = prev_excitation[idx3];
    }
}
