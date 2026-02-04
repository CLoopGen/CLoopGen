#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t pts_buf[17];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pts_buf[0] = -9223372036854775807L - 1;
    for (j = 1; j < 16 + 1; j++)
        pts_buf[j] = pts_buf[j-1]; // Introduce loop-carried WAW dependency
}
