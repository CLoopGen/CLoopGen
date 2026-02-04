#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bink_scan[64];
extern uint8_t inv_bink_scan[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[64];
    for (i = 0; i < 64; i++)
        temp[i] = bink_scan[i];
    for (i = 0; i < 64; i++)
        inv_bink_scan[temp[i]] = i;
}
