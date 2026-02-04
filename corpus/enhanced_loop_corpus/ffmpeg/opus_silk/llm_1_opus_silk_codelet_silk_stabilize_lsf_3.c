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
if (order > 1) {
    for (int outer = 1; outer < order; outer++) {
        i = outer;
        nlsf[i] = ((nlsf[i]) > (((nlsf[i - 1] + min_delta[i]) > (32767) ? (32767) : (nlsf[i - 1] + min_delta[i]))) ? (nlsf[i]) : (((nlsf[i - 1] + min_delta[i]) > (32767) ? (32767) : (nlsf[i - 1] + min_delta[i]))));
    }
}
}
