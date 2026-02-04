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
int total = x_size * y_size;
for (i = 0; i < total; i += 2) {
    if (*(midp + i) < 8) {
        uchar *inp_base = in + i - x_size - 1;
        inp = inp_base;
        *inp++ = 255; *inp++ = 255; *inp++ = 255;
        inp += x_size - 2;
        *inp++ = 255; inp++; *inp++ = 255;
        inp += x_size - 2;
        *inp++ = 255; *inp++ = 255; *inp = 255;
    }
    if (i + 1 < total && *(midp + i + 1) < 8) {
        uchar *inp_base = in + (i + 1) - x_size - 1;
        inp = inp_base;
        *inp++ = 255; *inp++ = 255; *inp++ = 255;
        inp += x_size - 2;
        *inp++ = 255; inp++; *inp++ = 255;
        inp += x_size - 2;
        *inp++ = 255; *inp++ = 255; *inp = 255;
    }
}
}
