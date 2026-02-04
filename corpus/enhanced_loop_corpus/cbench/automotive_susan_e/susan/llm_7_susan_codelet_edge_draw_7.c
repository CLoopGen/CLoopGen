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
    int offset;
    uchar temp_val;
    for (i = 0; i < x_size * y_size; i++) {
        temp_val = *midp;
        offset = midp - mid;
        midp++; // Advance midp early to break WAW/RAW dependency with subsequent iterations
        if (temp_val < 8) {
            uchar* write_ptr = in + offset - x_size - 1;
            *write_ptr = 255;
            *(write_ptr + 1) = 255;
            *(write_ptr + 2) = 255;
            write_ptr += x_size - 2;
            *++write_ptr = 255;
            write_ptr++;
            *write_ptr = 255;
            write_ptr += x_size - 2;
            *++write_ptr = 255;
            *++write_ptr = 255;
            *write_ptr = 255;
        }
    }
}
