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
    for (i = 0; i <= 0L; i++) {
        double diff = y - y_offset;
        double temp_alpha = alpha[i + 2];
        double temp_pixels = pixels[i + 2];
        if (diff >= 0.75) {
            alpha[i] = temp_alpha * 1.5;
            pixels[i] = temp_pixels * 1.5;
            alpha[i + 1] = temp_alpha * 0.5;
            pixels[i + 1] = temp_pixels * 0.5;
        } else if (diff > 0.25) {
            gamma = 4.0;
            alpha[i] = (alpha[i] + temp_alpha) * 0.8;
            pixels[i] = (pixels[i] + temp_pixels) * 0.8;
        }
    }
}
