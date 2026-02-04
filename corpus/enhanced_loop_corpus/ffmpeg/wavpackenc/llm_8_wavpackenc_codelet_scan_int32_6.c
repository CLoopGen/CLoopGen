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
for (i = 0; i < nb_samples; i += 2) {
    int32_t M1 = samples_l[i];
    crc = crc * 7 + (M1 & 65535) * 2 + ((M1 >> 16) & 65535);
    magdata |= (M1 < 0) ? ~M1 : M1;
    xordata ^= M1 ^ -(M1 & 1);
    anddata &= M1;
    ordata |= M1;

    if (i + 1 < nb_samples) {
        int32_t M2 = samples_l[i + 1];
        crc = crc * 7 + (M2 & 65535) * 2 + ((M2 >> 16) & 65535);
        magdata |= (M2 < 0) ? ~M2 : M2;
        xordata ^= M2 ^ -(M2 & 1);
        anddata &= M2;
        ordata |= M2;
    }
}
}
