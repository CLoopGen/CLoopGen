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
    int temp_red, temp_green, temp_blue;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 16; j++)
            for (x = 0; x < 256; x++) {
                // Introduce temporary variables to reorganize data dependencies
                // Eliminate repeated computation of 'value' by splitting into color-specific temps
                temp_red = x - 16;
                if (x < 48)
                    temp_red = x / 2 + 8;
                temp_red += dither_red[i][j];

                temp_green = x - 16;
                if (x < 48)
                    temp_green = x / 2 + 8;
                temp_green += dither_green[i][j];

                temp_blue = x - 32;
                if (x < 112)
                    temp_blue = x / 2 + 24;
                temp_blue += (int)(dither_blue[i][j] << 1);

                // Store results with clamping
                red_map[i][j][x] = (unsigned char)((temp_red < 0) ? 0 : (temp_red > 255) ? 255 : temp_red);
                green_map[i][j][x] = (unsigned char)((temp_green < 0) ? 0 : (temp_green > 255) ? 255 : temp_green);
                blue_map[i][j][x] = (unsigned char)((temp_blue < 0) ? 0 : (temp_blue > 255) ? 255 : temp_blue);
            }
}
