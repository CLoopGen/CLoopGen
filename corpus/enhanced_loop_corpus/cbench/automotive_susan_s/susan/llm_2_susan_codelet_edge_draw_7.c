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
        idx = i;
        if (*(mid + idx) < 8) {
            uchar* base = in + idx - x_size - 1;
            *(base) = 255;
            *(base + 1) = 255;
            *(base + 2) = 255;
            *(base + x_size + 1) = 255;
            *(base + x_size + 3) = 255;
            *(base + 2*x_size + 2) = 255;
            *(base + 2*x_size + 3) = 255;
            *(base + 2*x_size + 4) = 255;
        }
    }
}
