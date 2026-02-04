#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int8_t filt[64];
extern  int16_t *in;
extern int32_t sample;
extern int16_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sample = 0;
    for (j = 0; j < 64; j++) {
        int16_t val = in[j];
        if (val == 0) continue;
        sample += val * filt[j];
    }
}
