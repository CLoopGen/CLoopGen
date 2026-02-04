#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int base = i * 2;
        ungroup_3_in_7_bits_tab[base][0] = base / 25;
        ungroup_3_in_7_bits_tab[base][1] = (base % 25) / 5;
        ungroup_3_in_7_bits_tab[base][2] = (base % 25) % 5;
        ungroup_3_in_7_bits_tab[base + 1][0] = (base + 1) / 25;
        ungroup_3_in_7_bits_tab[base + 1][1] = ((base + 1) % 25) / 5;
        ungroup_3_in_7_bits_tab[base + 1][2] = ((base + 1) % 25) % 5;
    }
}
