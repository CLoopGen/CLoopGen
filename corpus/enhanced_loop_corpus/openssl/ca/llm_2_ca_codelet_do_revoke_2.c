#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every element with stride of 1 but in reverse order)
    for (i = 5; i >= 0; i--)
        row[i] = ((void *)0);
}
