#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i += 2) {
        int val1 = i / 25;
        int mod25 = i % 25;
        int val2 = mod25 / 5;
        int val3 = mod25 % 5;
        ungroup_3_in_7_bits_tab[i][0] = val1;
        ungroup_3_in_7_bits_tab[i][1] = val2;
        ungroup_3_in_7_bits_tab[i][2] = val3;
        if (i + 1 < 128) {
            int next = i + 1;
            int next_val1 = next / 25;
            int next_mod25 = next % 25;
            ungroup_3_in_7_bits_tab[next][0] = next_val1;
            ungroup_3_in_7_bits_tab[next][1] = next_mod25 / 5;
            ungroup_3_in_7_bits_tab[next][2] = next_mod25 % 5;
        }
    }
}
