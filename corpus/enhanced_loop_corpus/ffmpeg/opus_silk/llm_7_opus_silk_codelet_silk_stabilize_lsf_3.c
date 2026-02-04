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
    int16_t prev_nlsf = nlsf[0];
    for (i = 1; i < order; i++) {
        int16_t required_min = (prev_nlsf + min_delta[i] > 32767) ? 32767 : prev_nlsf + min_delta[i];
        nlsf[i] = (nlsf[i] > required_min) ? nlsf[i] : required_min;
        prev_nlsf = nlsf[i];
    }
}
