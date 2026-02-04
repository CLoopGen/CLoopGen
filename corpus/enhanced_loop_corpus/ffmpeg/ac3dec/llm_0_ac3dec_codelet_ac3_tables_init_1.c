#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 128; outer += 16) {
        for (int inner = 0; inner < 16 && (outer + inner) < 128; inner++) {
            int i = outer + inner;
            ungroup_3_in_7_bits_tab[i][0] = i / 25;
            ungroup_3_in_7_bits_tab[i][1] = (i % 25) / 5;
            ungroup_3_in_7_bits_tab[i][2] = (i % 25) % 5;
        }
    }
}
