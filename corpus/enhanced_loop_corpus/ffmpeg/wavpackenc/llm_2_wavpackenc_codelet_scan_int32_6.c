#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int nb_samples;
extern uint32_t magdata;
extern uint32_t ordata;
extern uint32_t xordata;
extern uint32_t anddata;
extern uint32_t crc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < nb_samples; i += 2) {
        int32_t M = samples_l[i];
        crc = crc * 9 + (M & 65535) * 3 + ((M >> 16) & 65535);
        magdata |= (M < 0) ? ~M : M;
        xordata |= M ^ -(M & 1);
        anddata &= M;
        ordata |= M;

        // Process next element if within bounds
        if (i + 1 < nb_samples) {
            int32_t M2 = samples_l[i + 1];
            crc = crc * 9 + (M2 & 65535) * 3 + ((M2 >> 16) & 65535);
            magdata |= (M2 < 0) ? ~M2 : M2;
            xordata |= M2 ^ -(M2 & 1);
            anddata &= M2;
            ordata |= M2;
        }
    }
}
