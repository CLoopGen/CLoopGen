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
    // Variant 2: Strided memory access with pointer arithmetic and stride pattern
    int total_elements = x_size * y_size;
    int stride = x_size;

    for (i = 0; i < total_elements; i += 1) {
        if (*(mid + i) < 8) {
            uchar *base_ptr = in + i - stride - 1;

            // Write top row: consecutive write of 3 elements
            *(base_ptr) = 255;
            *(base_ptr + 1) = 255;
            *(base_ptr + 2) = 255;

            // Middle row: strided access by skipping (stride - 2) elements
            base_ptr += stride;
            *(base_ptr) = 255;
            *(base_ptr + 2) = 255;

            // Bottom row: another stride jump and three writes
            base_ptr += stride;
            *(base_ptr) = 255;
            *(base_ptr + 1) = 255;
            *(base_ptr + 2) = 255;
        }
    }
}
