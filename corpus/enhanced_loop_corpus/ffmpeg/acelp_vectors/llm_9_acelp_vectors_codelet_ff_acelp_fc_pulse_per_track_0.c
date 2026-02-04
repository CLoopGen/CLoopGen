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
    int j;
    for (i = 0; i < pulse_count; i++) {
        fc_v[i + tab1[pulse_indexes & mask]] += (pulse_signs & 1) ? 8191 : -8192;
        for (j = 1; j < bits && (i + j) < pulse_count; j++) {
            fc_v[i + j + tab1[(pulse_indexes >> (j * bits)) & mask]] += ((pulse_signs >> j) & 1) ? 8191 : -8192;
        }
        pulse_indexes >>= bits;
        pulse_signs >>= bits;
        i += (bits > 1) ? bits - 1 : 0;
    }
}
