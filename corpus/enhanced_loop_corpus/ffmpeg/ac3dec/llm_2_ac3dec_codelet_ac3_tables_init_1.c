#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t ungroup_3_in_7_bits_tab[128][3];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic to traverse the array row by row
    uint8_t (*tab)[3] = ungroup_3_in_7_bits_tab;
    for (i = 0; i < 128; i++) {
        uint8_t val = i;
        uint8_t mod25 = val % 25;
        tab[i][0] = val / 25;
        tab[i][1] = mod25 / 5;
        tab[i][2] = mod25 % 5;
    }
}
