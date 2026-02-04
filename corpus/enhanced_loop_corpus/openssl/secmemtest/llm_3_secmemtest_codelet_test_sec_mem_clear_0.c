#include <stdio.h>

#include <inttypes.h>

extern  int size;
extern unsigned char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = size - 1; i >= 0; i--)
        p[i] = (unsigned char)(i + ' ' + 1);
}
