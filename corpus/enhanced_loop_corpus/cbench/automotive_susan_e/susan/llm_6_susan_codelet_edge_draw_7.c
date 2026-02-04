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
    int idx;
    for (i = 0; i < x_size * y_size; i++) {
        idx = midp - mid;
        if (*(mid + idx) < 8) {
            uchar* base_inp = in + idx - x_size - 1;
            *(base_inp) = 255;
            *(base_inp + 1) = 255;
            *(base_inp + 2) = 255;
            *(base_inp + x_size) = 255;
            *(base_inp + x_size + 2) = 255;
            *(base_inp + 2*x_size) = 255;
            *(base_inp + 2*x_size + 1) = 255;
            *(base_inp + 2*x_size + 2) = 255;
        }
        midp++;
    }
}
