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
// Use strided access pattern with reverse iteration on 'x' to modify memory access order
for (i = 0; i < 2; i++)
    for (j = 0; j < 16; j++)
        for (x = 255; x >= 0; x -= 4) {  // Reverse and strided access: step of 4
            int x1 = x, x2 = x-1, x3 = x-2, x4 = x-3;
            // Process four elements per iteration in reverse-strided pattern

            // Handle red_map
            value = x1 - 16; if (x1 < 48) value = x1 / 2 + 8; value += dither_red[i][j];
            red_map[i][j][x1] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            if (x2 >= 0) {
                value = x2 - 16; if (x2 < 48) value = x2 / 2 + 8; value += dither_red[i][j];
                red_map[i][j][x2] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
            if (x3 >= 0) {
                value = x3 - 16; if (x3 < 48) value = x3 / 2 + 8; value += dither_red[i][j];
                red_map[i][j][x3] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
            if (x4 >= 0) {
                value = x4 - 16; if (x4 < 48) value = x4 / 2 + 8; value += dither_red[i][j];
                red_map[i][j][x4] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }

            // Handle green_map
            value = x1 - 16; if (x1 < 48) value = x1 / 2 + 8; value += dither_green[i][j];
            green_map[i][j][x1] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            if (x2 >= 0) {
                value = x2 - 16; if (x2 < 48) value = x2 / 2 + 8; value += dither_green[i][j];
                green_map[i][j][x2] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
            if (x3 >= 0) {
                value = x3 - 16; if (x3 < 48) value = x3 / 2 + 8; value += dither_green[i][j];
                green_map[i][j][x3] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
            if (x4 >= 0) {
                value = x4 - 16; if (x4 < 48) value = x4 / 2 + 8; value += dither_green[i][j];
                green_map[i][j][x4] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }

            // Handle blue_map
            value = x1 - 32; if (x1 < 112) value = x1 / 2 + 24; value += (int)(dither_blue[i][j] << 1);
            blue_map[i][j][x1] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            if (x2 >= 0) {
                value = x2 - 32; if (x2 < 112) value = x2 / 2 + 24; value += (int)(dither_blue[i][j] << 1);
                blue_map[i][j][x2] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
            if (x3 >= 0) {
                value = x3 - 32; if (x3 < 112) value = x3 / 2 + 24; value += (int)(dither_blue[i][j] << 1);
                blue_map[i][j][x3] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
            if (x4 >= 0) {
                value = x4 - 32; if (x4 < 112) value = x4 / 2 + 24; value += (int)(dither_blue[i][j] << 1);
                blue_map[i][j][x4] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
        }
}
