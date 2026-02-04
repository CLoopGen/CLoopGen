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
    for (i = order - 2; i >= 0; i--) {
        int16_t temp = nlsf[i + 1] - min_delta[i + 1];
        if (nlsf[i] <= temp) continue;
        nlsf[i] = temp;
    }
}
