#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *fc_v;
extern  uint8_t *tab1;
extern int pulse_indexes;
extern int pulse_signs;
extern int pulse_count;
extern int bits;
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < pulse_count; i++) {
        int index = tab1[pulse_indexes & mask];
        int sign_bit = pulse_signs & 1;
        int adjustment = sign_bit ? 8191 : -8192;
        
        if (index >= 0) {
            fc_v[i + index] += adjustment;
        }
        
        pulse_indexes >>= bits;
        pulse_signs >>= 1;
    }
}
