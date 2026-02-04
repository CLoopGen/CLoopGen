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
    int16_t *base_v = fc_v;
    uint8_t *base_tab = tab1;
    int idx = pulse_indexes;
    int sign = pulse_signs;
    for (i = 0; i < pulse_count; i++) {
        int offset = base_tab[idx & mask];
        int16_t value = (sign & 1) ? 8191 : -8192;
        base_v[i + offset] += value;
        idx >>= bits;
        sign >>= 1;
    }
}
