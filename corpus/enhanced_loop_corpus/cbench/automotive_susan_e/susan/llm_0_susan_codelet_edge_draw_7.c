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
    int outer, inner;
    for (outer = 0; outer < y_size; outer++) {
        for (inner = 0; inner < x_size; inner++) {
            i = outer * x_size + inner;
            if (*(mid + i) < 8) {
                uchar *inp = in + i - x_size - 1;
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
}
