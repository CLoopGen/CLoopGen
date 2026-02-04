#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_val = 0;
for (i = 0; i < 128; i++) {
    ungroup_3_in_7_bits_tab[i][0] = (i + prev_val) / 25;
    ungroup_3_in_7_bits_tab[i][1] = ((i + prev_val) % 25) / 5;
    ungroup_3_in_7_bits_tab[i][2] = ((i + prev_val) % 25) % 5;
    prev_val = ungroup_3_in_7_bits_tab[i][0]; 
}
}
