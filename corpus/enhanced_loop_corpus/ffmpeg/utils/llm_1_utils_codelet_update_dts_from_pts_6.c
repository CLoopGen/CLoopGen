#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t pts_buffer[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (write from last to first element)
    for (i = 16; i >= 0; i--)
        pts_buffer[i] = ((int64_t)9223372036854775808UL);
}
