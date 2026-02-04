#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t pts_buf[17];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 16 + 1; j += 2) {
        pts_buf[j] = (-9223372036854775807L - 1);
        if (j + 1 <= 16)
            pts_buf[j + 1] = (-9223372036854775807L - 1);
    }
}
