#include <stdio.h>

#include <inttypes.h>

extern unsigned char *to;
extern int num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = num - 1; i >= 0; i--)
        to[i] = 0;
}
