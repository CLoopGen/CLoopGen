#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t pts_buffer[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 16 + 1; i++) {
    pts_buffer[i] = ((int64_t)9223372036854775808UL);
    for (j = 0; j < 4; j++) {
        pts_buffer[i] += (int64_t)(j * 100);
        pts_buffer[i] -= (int64_t)(j * 50);
    }
}
}
