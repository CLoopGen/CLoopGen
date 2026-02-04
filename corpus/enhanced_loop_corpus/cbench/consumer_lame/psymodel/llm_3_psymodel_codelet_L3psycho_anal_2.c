#include <stdio.h>

#include <inttypes.h>

extern int partition_l[513];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = 512; i >= 0; i--)
        partition_l[i] = -1;
}
