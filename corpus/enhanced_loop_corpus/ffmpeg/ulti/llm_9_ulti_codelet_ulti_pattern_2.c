#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f1;
extern int Y0;
extern int Y1;
extern uint8_t Luma[16];
extern int mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_mask = 128;
    int local_i = 8;
    while (local_mask) {
        if (f1 & local_mask) {
            Luma[local_i] = Y1;
            local_mask >>= 1;
            local_i++;
        } else {
            Luma[local_i] = Y0;
            local_mask >>= 1;
            local_i++;
        }
    }
}
