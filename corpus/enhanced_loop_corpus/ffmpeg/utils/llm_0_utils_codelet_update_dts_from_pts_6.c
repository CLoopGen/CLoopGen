#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t pts_buffer[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in increasing order, then fill gaps)
    for (i = 0; i < 17; i += 2)
        pts_buffer[i] = ((int64_t)9223372036854775808UL);
    for (i = 1; i < 17; i += 2)
        pts_buffer[i] = ((int64_t)9223372036854775808UL);
}
