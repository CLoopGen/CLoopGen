#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int offset[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with base pointer shift (simulate array view)
    int *base = offset + 3;
    for (i = 0; i < 5; i++)
        base[i] = 0;
}
