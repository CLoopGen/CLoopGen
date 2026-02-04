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
    for (i = 1; i < order; i++) {
        int16_t temp = nlsf[i - 1] + min_delta[i];
        if (temp > 32767) temp = 32767;
        if (nlsf[i] < temp) {
            nlsf[i] = temp;
        }
    }
}
