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
    int temp[16];
    for (mask = 128, i = 0; mask; mask >>= 1, i++) {
        temp[i] = (f0 & mask) ? Y1 : Y0;
    }
    for (i = 0; i < 16; i++) {
        Luma[i] = temp[i];
    }
}
