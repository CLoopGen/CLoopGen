#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write using pointer arithmetic in reverse order
    unsigned short *temp = x + 5;
    for (i = 0; i < 6; i++)
        *temp-- = 0;
}
