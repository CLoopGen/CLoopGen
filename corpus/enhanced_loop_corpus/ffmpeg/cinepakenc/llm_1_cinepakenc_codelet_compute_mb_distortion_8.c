#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *a_data[4];
extern int a_linesize[4];
extern uint8_t *b_data[4];
extern int b_linesize[4];
extern int x;
extern int y;
extern int d;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 2; y++)
    for (x = 0; x < 2; x++)
        for (int offset_y = 0; offset_y < 2; offset_y++)
            for (int offset_x = 0; offset_x < 2; offset_x++) {
                int abs_x = x * 2 + offset_x;
                int abs_y = y * 2 + offset_y;
                d = a_data[0][abs_x + abs_y * a_linesize[0]] - b_data[0][abs_x + abs_y * b_linesize[0]];
                ret += d * d;
            }
}
