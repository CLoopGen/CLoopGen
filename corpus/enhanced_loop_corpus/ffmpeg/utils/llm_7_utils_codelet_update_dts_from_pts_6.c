#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t pts_buffer[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    pts_buffer[i] = ((int64_t)9223372036854775808UL);
    pts_buffer[i + 1] = ((int64_t)9223372036854775808UL) + 1;
}
pts_buffer[16] = ((int64_t)9223372036854775808UL);
}
