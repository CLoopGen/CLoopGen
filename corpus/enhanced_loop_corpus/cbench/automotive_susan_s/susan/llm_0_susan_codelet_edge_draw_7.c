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
    int i, j;
    int total = x_size * y_size;
    for (i = 0; i < total; i++) {
        if (*(midp + i) < 8) {
            uchar *inp_base = in + i - x_size - 1;
            for (j = 0; j < 3; j++) {
                inp = inp_base + j * x_size;
                *inp++ = 255;
                *inp++ = 255;
                *inp = 255;
            }
        }
    }
}
