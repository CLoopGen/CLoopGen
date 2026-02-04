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
    int16_t k;
    for (j = 0, k = 63; j < 32; j++, k--) {
        sample += in[j] * filt[j];
        sample += in[k] * filt[k];
        sample += in[j] * filt[k];
        sample += in[k] * filt[j];
    }
}
