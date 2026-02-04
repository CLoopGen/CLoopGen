#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern  uint8_t *block;
extern int x;
extern int y;
extern int mn;
extern int mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_min = 255;
    int local_max = 0;
    uint8_t values[16];
    int i = 0;
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            values[i++] = block[3 + x * 4 + y * stride];
        }
    }
    for (i = 0; i < 16; i++) {
        if (values[i] < local_min)
            local_min = values[i];
        if (values[i] > local_max)
            local_max = values[i];
    }
    if (local_min < mn) mn = local_min;
    if (local_max > mx) mx = local_max;
}
