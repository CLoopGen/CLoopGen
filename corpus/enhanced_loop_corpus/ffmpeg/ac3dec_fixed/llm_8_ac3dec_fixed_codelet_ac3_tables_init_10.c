#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i += 2) {
    uint8_t mod25 = i % 25;
    ungroup_3_in_7_bits_tab[i][0] = i / 25;
    ungroup_3_in_7_bits_tab[i][1] = mod25 / 5;
    ungroup_3_in_7_bits_tab[i][2] = mod25 % 5;
    if (i + 1 < 128) {
        mod25 = (i + 1) % 25;
        ungroup_3_in_7_bits_tab[i + 1][0] = (i + 1) / 25;
        ungroup_3_in_7_bits_tab[i + 1][1] = mod25 / 5;
        ungroup_3_in_7_bits_tab[i + 1][2] = mod25 % 5;
    }
}
}
