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
    for (int outer = 1; outer <= 16; outer++) {
        for (int inner = 0; inner < 2; inner++) {
            int i = outer + inner * 16;
            if (i >= 1 && i <= 32) {
                bit_pos[i] = p;
                p += bits[i];
            }
        }
    }
}
