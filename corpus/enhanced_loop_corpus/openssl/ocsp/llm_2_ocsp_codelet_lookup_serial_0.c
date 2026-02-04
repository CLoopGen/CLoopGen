#include <stdio.h>

#include <inttypes.h>

extern int i;
extern char *row[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (reverse order with stride of 1)
    for (i = 5; i >= 0; i--)
        row[i] = ((void *)0);
}
