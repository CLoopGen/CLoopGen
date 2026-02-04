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



void loop() {
    // Variant 1: Consecutive memory access with precomputed indices
    int total_size = x_size * y_size;
    for (i = 0; i < total_size; i++) {
        if (mid[i] < 8) {
            int base_idx = i - x_size - 1;
            int offset1 = base_idx + 0;
            int offset2 = base_idx + x_size - 1;
            int offset3 = base_idx + 2 * x_size - 2;

            in[offset1] = 255;
            in[offset1 + 1] = 255;
            in[offset1 + 2] = 255;

            in[offset2] = 255;
            in[offset2 + 1] = 255;

            in[offset3] = 255;
            in[offset3 + 1] = 255;
            in[offset3 + 2] = 255;
        }
    }
}
