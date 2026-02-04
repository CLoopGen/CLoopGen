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
    int temp_indexes = pulse_indexes;
    int temp_signs = pulse_signs;
    int accumulated_update = 0;
    for (i = 0; i < pulse_count; i++) {
        int lookup = tab1[temp_indexes & mask];
        accumulated_update += (temp_signs & 1) ? 8191 : -8192;
        fc_v[i + lookup] += accumulated_update;
        accumulated_update = 0; 
        temp_indexes >>= bits;
        temp_signs >>= 1;
    }
}
