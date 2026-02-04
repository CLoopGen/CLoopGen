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
    for (i = 0; i < pulse_count * 2; i += 2) {
        int idx1 = tab1[pulse_indexes & mask];
        int idx2 = tab1[(pulse_indexes >> bits) & mask];
        int sign1 = (pulse_signs & 1) ? 8191 : -8192;
        int sign2 = ((pulse_signs >> 1) & 1) ? 8191 : -8192;
        fc_v[i/2 + idx1] += sign1;
        if (i + 1 < pulse_count) {
            fc_v[i/2 + 1 + idx2] += sign2;
        }
        pulse_indexes >>= (bits << 1);
        pulse_signs >>= 2;
    }
}
