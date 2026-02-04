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
    int idx, offset;
    int total_pixels = x_size * y_size;
    for (i = 0; i < total_pixels; i++) {
        if (*(mid + i) < 8) {
            idx = i - x_size - 1;
            for (int j = 0; j < 3; j++) {
                offset = idx + j * x_size;
                *(in + offset) = 255;
                *(in + offset + 1) = 255;
                *(in + offset + 2) = 255;
            }
        }
    }
    midp = mid + total_pixels; // Update midp to end position
}
