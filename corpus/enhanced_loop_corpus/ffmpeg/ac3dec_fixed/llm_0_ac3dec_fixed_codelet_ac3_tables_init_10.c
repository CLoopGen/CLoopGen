#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 128; i++) {
    for (int j = 0; j < 1; j++) {
        ungroup_3_in_7_bits_tab[i][0] = i / 25;
        ungroup_3_in_7_bits_tab[i][1] = (i % 25) / 5;
        ungroup_3_in_7_bits_tab[i][2] = (i % 25) % 5;
    }
}
}
