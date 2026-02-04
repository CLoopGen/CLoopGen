#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bink_scan[64];
extern uint8_t inv_bink_scan[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 8; outer++)
        for (int inner = 0; inner < 8; inner++)
            inv_bink_scan[bink_scan[outer * 8 + inner]] = outer * 8 + inner;
}
