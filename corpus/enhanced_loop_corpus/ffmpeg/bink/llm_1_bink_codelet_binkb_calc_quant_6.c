#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bink_scan[64];
extern uint8_t inv_bink_scan[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level1 = 0; level1 < 16; level1++)
        for (int level2 = 0; level2 < 4; level2++)
            for (int level3 = 0; level3 < 1; level3++) // Maintains logical single iteration per (level1, level2)
                inv_bink_scan[bink_scan[level1 * 4 + level2]] = level1 * 4 + level2;
}
