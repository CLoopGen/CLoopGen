#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bink_scan[64];
extern uint8_t inv_bink_scan[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 2) {
        inv_bink_scan[bink_scan[i]] = i;
        if (i + 1 < 64)
            inv_bink_scan[bink_scan[i + 1]] = i + 1;
    }
}
