#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned char buf[64];
extern  unsigned char xor_table[37];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 74; i++) {
        int index = i >> 1;
        if (index < 37) {
            buf[8 + index] ^= xor_table[index] + (i & 1);
        }
    }
}
