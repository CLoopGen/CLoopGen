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
    uint8_t local_Luma[16];
    int temp = 8;
    for (int m = 128; m; m >>= 1, temp++) {
        local_Luma[temp] = (f1 & m) ? Y1 : Y0;
    }
    for (int j = 8; j < 16; j++) {
        Luma[j] = local_Luma[j];
    }
}
