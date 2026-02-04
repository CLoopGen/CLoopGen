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
    for (int temp_mask = 128; temp_mask; temp_mask >>= 1) {
        for (int j = 0; j < 1; j++) {
            i = 8 + (128 - temp_mask) / temp_mask;
            if (f1 & temp_mask)
                Luma[i] = Y1;
            else
                Luma[i] = Y0;
        }
    }
}
