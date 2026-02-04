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
double prev_alpha = alpha[0];
double prev_pixels = pixels[0];
for (i = 0; i <= 1L; i++) {
    ssize_t next_idx = i + 2;
    if ((y - y_offset) >= 0.75) {
        alpha[i] = alpha[next_idx];
        pixels[i] = pixels[next_idx];
        prev_alpha = alpha[i];
        prev_pixels = pixels[i];
    } else if ((y - y_offset) > 0.25) {
        gamma = 2.;
        alpha[i] += prev_alpha;
        pixels[i] += prev_pixels;
    }
}
}
