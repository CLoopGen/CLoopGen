#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    if (i >= 100) {
        ungroup_3_in_7_bits_tab[i][0] = 4;
        ungroup_3_in_7_bits_tab[i][1] = (i - 100) / 5;
        ungroup_3_in_7_bits_tab[i][2] = (i - 100) % 5;
    } else if (i >= 75) {
        ungroup_3_in_7_bits_tab[i][0] = 3;
        ungroup_3_in_7_bits_tab[i][1] = (i - 75) / 5;
        ungroup_3_in_7_bits_tab[i][2] = (i - 75) % 5;
    } else if (i >= 50) {
        ungroup_3_in_7_bits_tab[i][0] = 2;
        ungroup_3_in_7_bits_tab[i][1] = (i - 50) / 5;
        ungroup_3_in_7_bits_tab[i][2] = (i - 50) % 5;
    } else if (i >= 25) {
        ungroup_3_in_7_bits_tab[i][0] = 1;
        ungroup_3_in_7_bits_tab[i][1] = (i - 25) / 5;
        ungroup_3_in_7_bits_tab[i][2] = (i - 25) % 5;
    } else {
        ungroup_3_in_7_bits_tab[i][0] = 0;
        ungroup_3_in_7_bits_tab[i][1] = i / 5;
        ungroup_3_in_7_bits_tab[i][2] = i % 5;
    }
}
}
