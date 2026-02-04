#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int block = 0; block < 128; block += 16) {
    for (i = block; i < block + 16 && i < 128; i++) {
        ungroup_3_in_7_bits_tab[i][0] = i / 25;
        ungroup_3_in_7_bits_tab[i][1] = (i % 25) / 5;
        ungroup_3_in_7_bits_tab[i][2] = (i % 25) % 5;
    }
}
}
