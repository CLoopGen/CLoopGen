#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int code;
extern char to[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse index calculation
    char temp[4];
    for (i = 0; i < 3; i++) {
        temp[2 - i] = 96 + (code & 31);
        code >>= 5;
    }
    for (i = 0; i < 3; i++) {
        to[i] = temp[i];
    }
}
