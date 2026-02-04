#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern  unsigned char *pixels;
extern int count;
extern ssize_t x;
extern unsigned char *q;
extern ssize_t j;
extern unsigned char packbits[128];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *pixel_ptr = pixels;
    unsigned char *output_ptr = q;
    unsigned char stride_buffer[129];

    for (x = (ssize_t)length; x > 0;) {
        switch (x) {
          case 1:
            {
                x--;
                output_ptr[0] = 0;
                output_ptr[1] = pixel_ptr[0];
                output_ptr += 2;
                pixel_ptr += 1;
                break;
            }
          case 2:
            {
                x -= 2;
                output_ptr[0] = 1;
                output_ptr[1] = pixel_ptr[0];
                output_ptr[2] = pixel_ptr[1];
                output_ptr += 3;
                pixel_ptr += 2;
                break;
            }
          case 3:
            {
                x -= 3;
                if (pixel_ptr[0] == pixel_ptr[1] && pixel_ptr[1] == pixel_ptr[2]) {
                    output_ptr[0] = 254;
                    output_ptr[1] = pixel_ptr[0];
                    output_ptr += 2;
                    pixel_ptr += 3;
                } else {
                    output_ptr[0] = 2;
                    output_ptr[1] = pixel_ptr[0];
                    output_ptr[2] = pixel_ptr[1];
                    output_ptr[3] = pixel_ptr[2];
                    output_ptr += 4;
                    pixel_ptr += 3;
                }
                break;
            }
          default:
            {
                if (pixel_ptr[0] == pixel_ptr[1] && pixel_ptr[1] == pixel_ptr[2]) {
                    ssize_t c;
                    for (c = 3; c < x && c < 127; c++) {
                        if (pixel_ptr[c] != pixel_ptr[0]) break;
                    }
                    x -= c;
                    output_ptr[0] = (unsigned char)(257 - c);
                    output_ptr[1] = pixel_ptr[0];
                    output_ptr += 2;
                    pixel_ptr += c;
                } else {
                    ssize_t c;
                    for (c = 0; c < 127 && (c + 3) <= x; c++) {
                        stride_buffer[c + 1] = pixel_ptr[c];
                        if (pixel_ptr[c] == pixel_ptr[c+1] && pixel_ptr[c+1] == pixel_ptr[c+2])
                            break;
                    }
                    x -= c;
                    stride_buffer[0] = (unsigned char)(c - 1);
                    for (j = 0; j <= c; j++) {
                        output_ptr[j] = stride_buffer[j];
                    }
                    output_ptr += (c + 1);
                    pixel_ptr += c;
                }
                break;
            }
        }
    }

    // Update the external pointers after processing
    q = output_ptr;
    pixels = pixel_ptr;
}
