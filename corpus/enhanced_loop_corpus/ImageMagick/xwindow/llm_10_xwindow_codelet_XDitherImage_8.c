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
    for (j = 0; j < 16; j += 2)
        for (x = 0; x < 512; x++) {
            int offset = (x >> 8) * 256;
            int base_val_red = (x & 255) - 16;
            value = (x & 255) < 48 ? ((x & 255) / 2 + 8) : base_val_red;
            value += dither_red[i][j];
            red_map[i][j][x & 255] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            if (j + 1 < 16) {
                value = (x & 255) - 16;
                if ((x & 255) < 48)
                    value = (x & 255) / 2 + 8;
                value += dither_red[i][j+1];
                red_map[i][j+1][x & 255] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }

            value = (x & 255) - 16;
            if ((x & 255) < 48)
                value = (x & 255) / 2 + 8;
            value += dither_green[i][j];
            green_map[i][j][x & 255] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            if (j + 1 < 16) {
                value = (x & 255) - 16;
                if ((x & 255) < 48)
                    value = (x & 255) / 2 + 8;
                value += dither_green[i][j+1];
                green_map[i][j+1][x & 255] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }

            value = (x & 255) - 32;
            if ((x & 255) < 112)
                value = (x & 255) / 2 + 24;
            value += (int)(dither_blue[i][j] << 1);
            blue_map[i][j][x & 255] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            if (j + 1 < 16) {
                value = (x & 255) - 32;
                if ((x & 255) < 112)
                    value = (x & 255) / 2 + 24;
                value += (int)(dither_blue[i][j+1] << 1);
                blue_map[i][j+1][x & 255] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
        }

}
