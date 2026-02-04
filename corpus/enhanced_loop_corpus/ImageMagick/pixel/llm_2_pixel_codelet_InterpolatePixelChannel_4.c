#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double y;
extern double alpha[16];
extern double gamma;
extern double pixels[16];
extern ssize_t i;
extern ssize_t y_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i <= 2L; i += 2) {
        ssize_t idx = i / 2;
        if ((y - y_offset) >= 0.75) {
            alpha[idx] = alpha[idx + 2];
            pixels[idx] = pixels[idx + 2];
        } else if ((y - y_offset) > 0.25) {
            gamma = 2.;
            alpha[idx] += alpha[idx + 2];
            pixels[idx] += pixels[idx + 2];
        }
    }
}
