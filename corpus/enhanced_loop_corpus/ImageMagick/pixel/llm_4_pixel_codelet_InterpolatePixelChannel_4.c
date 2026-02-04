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
    double diff = y - y_offset;
    if (diff >= 0.75) {
        alpha[i] = alpha[i + 2];
        pixels[i] = pixels[i + 2];
    } else {
        gamma = 2.;
        alpha[i] += alpha[i + 2];
        pixels[i] += pixels[i + 2];
    }
}
}
