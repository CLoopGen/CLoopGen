#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 0; level1 < 4; level1++) {
        for (int level2 = 0; level2 < 4; level2++) {
            for (int level3 = 0; level3 < 8; level3++) {
                int i = (level1 * 32) + (level2 * 8) + level3;
                if (i < 128) {
                    ungroup_3_in_7_bits_tab[i][0] = i / 25;
                    ungroup_3_in_7_bits_tab[i][1] = (i % 25) / 5;
                    ungroup_3_in_7_bits_tab[i][2] = (i % 25) % 5;
                }
            }
        }
    }
}
