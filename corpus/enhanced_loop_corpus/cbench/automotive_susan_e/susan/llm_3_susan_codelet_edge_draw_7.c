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
for (i = 0; i < x_size * y_size; i += 2) {
    int idx1 = i;
    int idx2 = i + 1;
    int cond1 = 0, cond2 = 0;
    if (idx1 < x_size * y_size && *(mid + idx1) < 8) cond1 = 1;
    if (idx2 < x_size * y_size && *(mid + idx2) < 8) cond2 = 1;

    if (cond1) {
        uchar *p = in + idx1 - x_size - 1;
        for (int j = 0; j < 3; j++) *p++ = 255;
        p += x_size - 2;
        *p++ = 255; p++; *p = 255;
        p += x_size - 2;
        for (int j = 0; j < 3; j++) *p++ = 255;
    }

    if (cond2) {
        uchar *p = in + idx2 - x_size - 1;
        for (int j = 0; j < 3; j++) *p++ = 255;
        p += x_size - 2;
        *p++ = 255; p++; *p = 255;
        p += x_size - 2;
        for (int j = 0; j < 3; j++) *p++ = 255;
    }
}
}
