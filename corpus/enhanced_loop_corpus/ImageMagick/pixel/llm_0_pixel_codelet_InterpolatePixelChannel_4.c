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
        for (ssize_t j = 0; j < 2; j++) {
            if ((y - y_offset) >= 0.75) {
                alpha[i] = alpha[i + 2];
                pixels[i] = pixels[i + 2];
            } else if ((y - y_offset) > 0.25) {
                gamma = 2.;
                alpha[i] += alpha[i + 2];
                pixels[i] += pixels[i + 2];
            }
        }
    }
}
