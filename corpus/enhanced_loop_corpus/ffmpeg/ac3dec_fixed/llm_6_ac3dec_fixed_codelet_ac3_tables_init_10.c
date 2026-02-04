#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp0, temp1, temp2;
    for (i = 0; i < 128; i++) {
        temp0 = i / 25;
        temp1 = (i - temp0 * 25) / 5;
        temp2 = i - temp0 * 25 - temp1 * 5;
        ungroup_3_in_7_bits_tab[i][0] = temp0;
        ungroup_3_in_7_bits_tab[i][1] = temp1;
        ungroup_3_in_7_bits_tab[i][2] = temp2;
    }
}
