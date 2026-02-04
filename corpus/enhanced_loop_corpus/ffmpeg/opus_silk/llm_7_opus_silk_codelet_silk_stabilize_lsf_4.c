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
    for (i = 0; i < order - 1; i++) {
        int idx = order - 2 - i;
        if (nlsf[idx] > nlsf[idx + 1] - min_delta[idx + 1])
            nlsf[idx] = nlsf[idx + 1] - min_delta[idx + 1];
    }
}
