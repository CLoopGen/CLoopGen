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
    for (int j = 0; j < y_size; j++) {
        for (int k = 0; k < x_size; k++) {
            i = j * x_size + k;
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
