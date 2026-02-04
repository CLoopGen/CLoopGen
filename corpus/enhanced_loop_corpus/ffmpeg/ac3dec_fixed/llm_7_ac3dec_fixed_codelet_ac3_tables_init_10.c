#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t val0, val1, val2;
    for (i = 0; i < 128; i++) {
        int remainder = i % 25;
        val2 = remainder % 5;
        val1 = remainder / 5;
        val0 = i / 25;
        ungroup_3_in_7_bits_tab[i][2] = val2;
        ungroup_3_in_7_bits_tab[i][1] = val1;
        ungroup_3_in_7_bits_tab[i][0] = val0;
    }
}
