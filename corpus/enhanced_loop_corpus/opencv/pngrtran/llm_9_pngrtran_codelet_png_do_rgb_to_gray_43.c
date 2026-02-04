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



void loop(){
for (i = 0; i < row_width; i++) {
    png_uint_16 red, green, blue, gray16;
    png_byte hi, lo;

    // Combine bit manipulation with additional arithmetic to increase computational intensity
    hi = *(sp)++;
    lo = *(sp)++;
    red = (png_uint_16)((hi << 8) | lo);

    hi = *(sp)++;
    lo = *(sp)++;
    green = (png_uint_16)((hi << 8) | lo);

    hi = *(sp)++;
    lo = *(sp)++;
    blue = (png_uint_16)((hi << 8) | lo);

    // Enhanced error checking with extra logical operations
    if ((red ^ green) != 0 || (red ^ blue) != 0)
        rgb_error |= (1 + ((red + green + blue) & 1));  // Slight variation in update

    // Increased arithmetic complexity: simulate higher precision with extra ops
    png_uint_32 weighted_sum = rc * red + gc * green + bc * blue;
    weighted_sum += (weighted_sum >> 14) + 16384;  // Additional bias and feedback-like term
    gray16 = (png_uint_16)(weighted_sum >> 15);

    // Write output with expanded masking (redundant but increases computation)
    *(dp++) = (png_byte)((gray16 >> 8) & 0xFFU);
    *(dp++) = (png_byte)(gray16 & 0xFFU);

    if (have_alpha) {
        // Process alpha with dummy operation to increase load
        png_byte alpha_hi = *(sp)++;
        png_byte alpha_lo = *(sp)++;
        *(dp++) = (png_byte)(alpha_hi ^ 0x00);  // Dummy XOR
        *(dp++) = alpha_lo;
    }
}
}
