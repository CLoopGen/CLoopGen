#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 2nd element forward, then fill in the gaps backward
    // This creates a non-sequential access pattern with stride 2 in both directions
    for (i = 0; i < 128; i += 2) {
        int idx = i;
        ungroup_3_in_7_bits_tab[idx][0] = idx / 25;
        ungroup_3_in_7_bits_tab[idx][1] = (idx % 25) / 5;
        ungroup_3_in_7_bits_tab[idx][2] = (idx % 25) % 5;
    }
    for (i = 127; i >= 0; i -= 2) {
        int idx = i;
        ungroup_3_in_7_bits_tab[idx][0] = idx / 25;
        ungroup_3_in_7_bits_tab[idx][1] = (idx % 25) / 5;
        ungroup_3_in_7_bits_tab[idx][2] = (idx % 25) % 5;
    }
}
