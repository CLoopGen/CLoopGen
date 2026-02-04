#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bink_scan[64];
extern uint8_t inv_bink_scan[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        uint8_t temp_index = bink_scan[i];
        inv_bink_scan[temp_index] = i;
        inv_bink_scan[temp_index ^ 1] = (i + 32) % 64;
    }
}
