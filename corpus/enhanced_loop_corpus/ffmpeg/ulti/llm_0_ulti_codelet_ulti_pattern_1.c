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
    for (int depth1 = 0; depth1 < 1; depth1++) {
        for (mask = 128, i = 0; mask; mask >>= 1, i++) {
            if (f0 & mask)
                Luma[i] = Y1;
            else
                Luma[i] = Y0;
        }
    }
}
