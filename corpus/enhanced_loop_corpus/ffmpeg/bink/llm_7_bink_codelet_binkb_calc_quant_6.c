#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t bink_scan[64];
extern uint8_t inv_bink_scan[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_inv[64];
    for (i = 0; i < 64; i++)
        local_inv[i] = i;
    for (i = 0; i < 64; i++)
        inv_bink_scan[bink_scan[i]] = local_inv[i];
}
