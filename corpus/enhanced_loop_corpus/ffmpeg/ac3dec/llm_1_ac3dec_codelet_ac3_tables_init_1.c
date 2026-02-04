#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 8; depth1++) {
        for (int depth2 = 0; depth2 < 16; depth2++) {
            int i = depth1 * 16 + depth2;
            if (i >= 128) continue;
            ungroup_3_in_7_bits_tab[i][0] = i / 25;
            ungroup_3_in_7_bits_tab[i][1] = (i % 25) / 5;
            ungroup_3_in_7_bits_tab[i][2] = (i % 25) % 5;
        }
    }
}
