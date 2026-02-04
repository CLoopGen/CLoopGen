#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 2nd element in two passes to create non-unit stride
    uint8_t (*tab)[3] = ungroup_3_in_7_bits_tab;
    // First pass: even indices
    for (i = 0; i < 128; i += 2) {
        int mod25 = i % 25;
        tab[i][0] = i / 25;
        tab[i][1] = mod25 / 5;
        tab[i][2] = mod25 % 5;
    }
    // Second pass: odd indices
    for (i = 1; i < 128; i += 2) {
        int mod25 = i % 25;
        tab[i][0] = i / 25;
        tab[i][1] = mod25 / 5;
        tab[i][2] = mod25 % 5;
    }
}
