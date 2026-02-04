#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bink_scan[64];
extern uint8_t inv_bink_scan[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; ++i) {
        uint8_t val = bink_scan[i];
        if (val != 0 && (val & 1)) {
            inv_bink_scan[val] = i;
        } else {
            inv_bink_scan[val] = i + 1;
        }
    }
}
