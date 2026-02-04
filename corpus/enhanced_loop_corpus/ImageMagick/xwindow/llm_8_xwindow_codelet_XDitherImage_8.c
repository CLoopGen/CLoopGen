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
    // Introduce loop-carried dependency via accumulation across x iterations
    // Modify data flow: make current iteration depend on previous via running adjustment
    int acc_dither = 0;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 16; j++) {
            acc_dither = 0; // Reset accumulator per [i][j]
            for (x = 0; x < 256; x++) {
                // Create loop-carried dependency: acc_dither carries over from previous x
                acc_dither = (acc_dither + dither_red[i][j] + dither_green[i][j]) & 0xFF;

                value = x - 16;
                if (x < 48)
                    value = x / 2 + 8;
                // Add accumulated dither, creating RAW and loop-carried WAW dependency
                red_map[i][j][x] = (unsigned char)((value + acc_dither < 0) ? 0 : (value + acc_dither > 255) ? 255 : value + acc_dither);

                value = x - 16;
                if (x < 48)
                    value = x / 2 + 8;
                green_map[i][j][x] = (unsigned char)((value + acc_dither < 0) ? 0 : (value + acc_dither > 255) ? 255 : value + acc_dither);

                value = x - 32;
                if (x < 112)
                    value = x / 2 + 24;
                // Blue uses original dither only (no acc), reducing uniformity
                value += (int)(dither_blue[i][j] << 1);
                blue_map[i][j][x] = (unsigned char)((value < 0) ? 0 : (value > 255) ? 255 : value);
            }
        }
}
