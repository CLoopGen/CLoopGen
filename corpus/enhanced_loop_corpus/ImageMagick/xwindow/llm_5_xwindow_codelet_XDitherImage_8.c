#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  short dither_red[2][16];
extern  short dither_green[2][16];
extern  short dither_blue[2][16];
extern int i;
extern int j;
extern int value;
extern int x;
extern unsigned char *blue_map[2][16];
extern unsigned char *green_map[2][16];
extern unsigned char *red_map[2][16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i++)
    for (j = 0; j < 16; j++)
        for (x = 0; x < 256; x++) {
            // Precompute conditions to reduce branching
            int cond_red_green = (x < 48);
            int cond_blue = (x < 112);

            value = cond_red_green ? (x / 2 + 8) : (x - 16);
            value += dither_red[i][j];
            red_map[i][j][x] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);

            value = cond_red_green ? (x / 2 + 8) : (x - 16);
            value += dither_green[i][j];
            green_map[i][j][x] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);

            value = cond_blue ? (x / 2 + 24) : (x - 32);
            value += (int)(dither_blue[i][j] << 1);
            blue_map[i][j][x] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
        }
}
