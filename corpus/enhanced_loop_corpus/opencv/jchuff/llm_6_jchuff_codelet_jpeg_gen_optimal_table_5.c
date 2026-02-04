#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char UINT8;

extern UINT8 bits[33];
extern int bit_pos[33];
extern int p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_pos[33] = {0};
    for (i = 1; i <= 32; i++) {
        temp_pos[i] = p;
        p += bits[i];
        bit_pos[i] = temp_pos[i];
    }
}
