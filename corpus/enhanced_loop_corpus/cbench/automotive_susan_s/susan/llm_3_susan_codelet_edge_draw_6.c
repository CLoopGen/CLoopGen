#include <stdio.h>

#include <inttypes.h>

typedef unsigned char uchar;

extern uchar *in;
extern uchar *mid;
extern int x_size;
extern int y_size;
extern int i;
extern uchar *midp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with fixed stride of 4
    int total_size = x_size * y_size;
    int stride = 4;
    uchar *in_base = in;
    uchar *midp_base = midp;
    
    // Access memory with stride: process every 4th element first, then offset
    for (int offset = 0; offset < stride; offset++) {
        for (i = offset; i < total_size; i += stride) {
            uchar *current_midp = midp_base + i;
            if (*current_midp < 8)
                *(in_base + (current_midp - mid)) = 0;
        }
    }
}
