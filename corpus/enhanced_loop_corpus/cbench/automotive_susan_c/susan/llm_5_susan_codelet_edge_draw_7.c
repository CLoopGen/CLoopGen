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
    midp++;
    if (*(midp - 1) < 8) {
        inp = in + (midp - 1 - mid) - x_size - 1;
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
}
}
