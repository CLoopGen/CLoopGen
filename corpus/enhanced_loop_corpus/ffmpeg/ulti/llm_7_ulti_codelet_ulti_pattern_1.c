#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f0;
extern int Y0;
extern int Y1;
extern uint8_t Luma[16];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_Luma[16];
    int prev_i = 0;
    for (mask = 128, i = 0; mask; mask >>= 1, i++) {
        if (i > 0) {
            local_Luma[i] = (f0 & mask) ? Y1 + (local_Luma[prev_i] % 4) : Y0 + (local_Luma[prev_i] % 3);
        } else {
            local_Luma[i] = (f0 & mask) ? Y1 : Y0;
        }
        prev_i = i;
    }
    for (i = 0; i < 16; i++) {
        Luma[i] = local_Luma[i];
    }
}
