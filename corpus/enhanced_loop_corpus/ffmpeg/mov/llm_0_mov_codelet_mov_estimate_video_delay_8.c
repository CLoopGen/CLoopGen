#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t pts_buf[17];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++)
        for (j = 0; j < 16 + 1; j++)
            pts_buf[j] = (-9223372036854775807L - 1);
}
