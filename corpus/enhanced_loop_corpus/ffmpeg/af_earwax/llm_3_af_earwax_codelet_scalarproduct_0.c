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
    // Variant 2: Reverse sequential access – process array from end to start
    // Alters memory access pattern to descending index order
    sample = 0; // Reset sample to ensure clean accumulation
    int16_t j;
    for (j = 63; j >= 0; j--) {
        sample += in[j] * filt[j];
    }
}
