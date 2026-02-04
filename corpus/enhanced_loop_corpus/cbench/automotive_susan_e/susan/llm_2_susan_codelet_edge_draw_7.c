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
    int idx = i;
    if (*(mid + idx) < 8) {
        int base_offset = idx - x_size - 1;
        int offset = base_offset;
        *(in + offset++) = 255;
        *(in + offset++) = 255;
        *(in + offset) = 255;
        offset += x_size - 2;
        *(in + offset++) = 255;
        offset++;
        *(in + offset) = 255;
        offset += x_size - 2;
        *(in + offset++) = 255;
        *(in + offset++) = 255;
        *(in + offset) = 255;
    }
}
}
