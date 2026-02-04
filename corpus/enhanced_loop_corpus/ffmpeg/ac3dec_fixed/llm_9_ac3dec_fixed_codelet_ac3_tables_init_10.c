#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i++) {
    ungroup_3_in_7_bits_tab[i][0] = (2 * i) / 25;
    ungroup_3_in_7_bits_tab[i][1] = ((2 * i) % 25) / 5;
    ungroup_3_in_7_bits_tab[i][2] = ((2 * i) % 25) % 5;
    ungroup_3_in_7_bits_tab[i + 64][0] = (2 * i + 1) / 25;
    ungroup_3_in_7_bits_tab[i + 64][1] = ((2 * i + 1) % 25) / 5;
    ungroup_3_in_7_bits_tab[i + 64][2] = ((2 * i + 1) % 25) % 5;
}
}
