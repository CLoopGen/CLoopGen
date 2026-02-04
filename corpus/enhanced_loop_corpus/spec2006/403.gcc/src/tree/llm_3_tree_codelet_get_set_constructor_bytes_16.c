#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buffer;
extern int wd_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backwards traversal)
    for (i = wd_size - 1; i >= 0; i--)
        buffer[i] = 0;
}
