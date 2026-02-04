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
    int16_t temp;
    for (i = order - 2; i >= 0; i--) {
        temp = nlsf[i + 1] - min_delta[i + 1];
        if (nlsf[i] > temp)
            nlsf[i] = temp;
    }
}
