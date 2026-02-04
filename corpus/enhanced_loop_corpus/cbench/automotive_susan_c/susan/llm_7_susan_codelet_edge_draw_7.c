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
    int j;
    uchar *temp_midp = mid;
    for (j = 0; j < x_size * y_size; j++) {
        if (*temp_midp < 8) {
            int offset = temp_midp - mid;
            uchar *write_ptr = in + offset - x_size - 1;
            // Introduce artificial write-after-write dependency by splitting stores
            *write_ptr = 255;
            *(write_ptr + 1) = 255;
            *(write_ptr + 2) = 255;
            *(write_ptr + x_size + 2) = 255;
            *(write_ptr + 2*x_size + 2) = 255;
            *(write_ptr + 2*x_size + 1) = 255;
            *(write_ptr + 2*x_size) = 255;
            *(write_ptr + x_size) = 255; // WAW: Overwriting same region with reordered writes
        }
        temp_midp++;
    }
    // Loop-carried dependence eliminated: using local induction variable j and temp pointer
    // Original global side effect on midp removed; no mutation of external midp
}
