#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bink_scan[64];
extern uint8_t inv_bink_scan[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse indirect access – traverse bink_scan in reverse order but still assign correct index
    for (i = 63; i >= 0; i--) {
        uint8_t val = bink_scan[i];
        inv_bink_scan[val] = i;
    }
}
