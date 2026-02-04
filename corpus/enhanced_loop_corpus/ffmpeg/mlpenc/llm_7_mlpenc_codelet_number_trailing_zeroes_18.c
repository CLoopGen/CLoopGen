#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t sample;
extern int bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_bits = 0;
    int32_t local_sample = sample;
    for (; local_bits < 24; local_bits++) {
        if (local_sample & (1 << local_bits)) {
            break;
        }
    }
    bits = local_bits; // Remove loop-carried dependency on 'bits' by using local induction variable
}
