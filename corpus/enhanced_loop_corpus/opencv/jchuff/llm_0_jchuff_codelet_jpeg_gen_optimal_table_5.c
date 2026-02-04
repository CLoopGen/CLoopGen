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
    for (int level1 = 1; level1 <= 32; level1++) {
        for (int level2 = level1; level2 <= level1; level2++) {
            bit_pos[level2] = p;
            p += bits[level2];
        }
    }
}
