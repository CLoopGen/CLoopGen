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
    int temp_i = i;
    int temp_mask = mask;
    for (temp_mask = 128, temp_i = 8; temp_mask; temp_mask >>= 1, temp_i++) {
        Luma[temp_i] = (f1 & temp_mask) ? Y1 : Y0;
    }
    i = temp_i;
    mask = temp_mask;
}
