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
    for (int outer = 0; outer < 2; outer++) {
        for (mask = 128, i = 0; mask && i < 8; mask >>= 1, i++) {
            if (f0 & mask)
                Luma[i + outer * 8] = Y1;
            else
                Luma[i + outer * 8] = Y0;
        }
    }
}
