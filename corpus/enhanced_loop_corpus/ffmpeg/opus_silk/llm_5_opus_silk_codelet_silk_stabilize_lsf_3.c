#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t nlsf[16];
extern int order;
extern  uint16_t min_delta[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < order && order > 0; i++) {
        int16_t prev_plus_delta = nlsf[i - 1] + min_delta[i];
        int16_t bounded_val = (prev_plus_delta > 32767) ? 32767 : prev_plus_delta;
        nlsf[i] = (nlsf[i] > bounded_val) ? nlsf[i] : bounded_val;
        if (nlsf[i] == 32767) continue;
    }
}
