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
for (i = 0; i < x_size * y_size; i++) {
    if (*midp < 8) {
        inp = in + (midp - mid) - x_size - 1;
        *inp++ = 255;
        *inp++ = 255;
        *inp = 255;
        inp += x_size - 2;
        *inp++ = 255;
        if ((midp - mid) % 2 == 0) {
            inp++;
        } else {
            inp += 2;
        }
        *inp = 255;
        inp += x_size - 2;
        *inp++ = 255;
        *inp++ = 255;
        *inp = 255;
    }
    midp++;
}
}
