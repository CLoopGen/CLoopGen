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
    for (i = 32; i >= 1; i--) {
        bit_pos[i] = p;
        p += bits[i] * (i % 4 + 1);
    }
}
