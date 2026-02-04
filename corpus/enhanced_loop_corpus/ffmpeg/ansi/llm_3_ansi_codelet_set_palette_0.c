#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_buffer[216];
    int idx = 0;
    for (b = 0; b < 6; b++)
        for (g = 0; g < 6; g++)
            for (r = 0; r < 6; r++)
                temp_buffer[idx++] = 4278190080U | (((r) * 40 + 55) << 16) | (((g) * 40 + 55) << 8) | ((b) * 40 + 55);
    for (int i = 0; i < 216; i++)
        *pal++ = temp_buffer[i];
}
