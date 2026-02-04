#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int i;
extern uchar *inp;
extern uchar *midp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_pixels = x_size * y_size;
    for (i = 0; i < total_pixels; i += 2) {
        if (*midp < 8) {
            inp = in + (midp - mid) - x_size - 1;
            *inp++ = 255;
            *inp++ = 255;
            *inp = 255;
            inp += x_size - 2;
            *inp++ = 255;
            inp++;
            *inp = 255;
            inp += x_size - 2;
            *inp++ = 255;
            *inp++ = 255;
            *inp = 255;
        }
        midp++;
        if (i + 1 < total_pixels) {
            midp++;
        }
    }
}
