#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i += 2) {
    int temp = i % 25;
    ungroup_3_in_7_bits_tab[i][0] = i / 25;
    ungroup_3_in_7_bits_tab[i][1] = temp / 5;
    ungroup_3_in_7_bits_tab[i][2] = temp % 5;
    if (i + 1 < 128) {
        temp = (i + 1) % 25;
        ungroup_3_in_7_bits_tab[i+1][0] = (i + 1) / 25;
        ungroup_3_in_7_bits_tab[i+1][1] = temp / 5;
        ungroup_3_in_7_bits_tab[i+1][2] = temp % 5;
    }
}
}
