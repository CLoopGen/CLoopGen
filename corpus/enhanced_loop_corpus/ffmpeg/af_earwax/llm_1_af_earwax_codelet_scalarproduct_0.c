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
    for (j = 0; j < 32; j++) {
        sample += in[j] * filt[j];
        sample += in[j + 32] * filt[j + 32];
    }
}
