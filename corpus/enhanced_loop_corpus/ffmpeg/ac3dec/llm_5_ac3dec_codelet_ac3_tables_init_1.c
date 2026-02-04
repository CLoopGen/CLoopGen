#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    int mod25 = i % 25;
    ungroup_3_in_7_bits_tab[i][0] = i / 25;
    if (mod25 >= 20) {
        ungroup_3_in_7_bits_tab[i][1] = 4;
        ungroup_3_in_7_bits_tab[i][2] = mod25 - 20;
    } else {
        ungroup_3_in_7_bits_tab[i][1] = mod25 / 5;
        ungroup_3_in_7_bits_tab[i][2] = mod25 % 5;
    }
}
}
