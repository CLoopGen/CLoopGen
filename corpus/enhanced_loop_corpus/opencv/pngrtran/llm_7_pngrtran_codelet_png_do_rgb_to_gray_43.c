#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int png_uint_32;

typedef unsigned char png_byte;

typedef png_byte *png_bytep;

typedef unsigned short png_uint_16;

extern int rgb_error;
extern png_uint_32 rc;
extern png_uint_32 gc;
extern png_uint_32 bc;
extern png_uint_32 row_width;
extern int have_alpha;
extern png_bytep sp;
extern png_bytep dp;
extern png_uint_32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < row_width; i++) {
        png_uint_16 red, green, blue, gray16;
        png_byte hi, lo;

        // Combine reads into a single sequence without intermediate reassignment to 'hi'/'lo'
        // This removes some WAR/WAW hazards on hi/lo and reduces register pressure
        red = (png_uint_16)(((*sp) << 8) | (*(sp + 1)));
        sp += 2;
        green = (png_uint_16)(((*sp) << 8) | (*(sp + 1)));
        sp += 2;
        blue = (png_uint_16)(((*sp) << 8) | (*(sp + 1)));
        sp += 2;

        // Introduce loop-carried dependency via cumulative error tracking (RAW across iterations)
        if (red != green || red != blue) {
            rgb_error = (rgb_error + 1) & 1;  // Still caps at 1, but now has artificial dependency
        }

        // Delayed write to dp: batch compute both bytes before writing
        gray16 = (png_uint_16)((rc * red + gc * green + bc * blue + 16384) >> 15);
        png_byte gray_out[2] = { (png_byte)((gray16 >> 8) & 255), (png_byte)(gray16 & 255) };
        *dp++ = gray_out[0];
        *dp++ = gray_out[1];

        if (have_alpha) {
            // Fold alpha copy into vector-like access to increase stride predictability
            *(dp++) = *(sp++);
            *(dp++) = *(sp++);
        }
    }
}
