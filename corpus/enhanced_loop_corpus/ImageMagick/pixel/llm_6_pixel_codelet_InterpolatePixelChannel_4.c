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
for (i = 0; i <= 1L; i++) {
    ssize_t j = i + 2;
    double temp_alpha = alpha[j];
    double temp_pixels = pixels[j];
    if ((y - y_offset) >= 0.75) {
        alpha[i] = temp_alpha;
        pixels[i] = temp_pixels;
    } else if ((y - y_offset) > 0.25) {
        gamma = 2.;
        alpha[i] += temp_alpha;
        pixels[i] += temp_pixels;
    }
}
}
