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
    for (mask = 128, i = 8; mask; mask >>= 1, i++) {
        if (!(f1 & mask)) {
            Luma[i] = Y0;
            continue;
        }
        Luma[i] = Y1;
    }
}
