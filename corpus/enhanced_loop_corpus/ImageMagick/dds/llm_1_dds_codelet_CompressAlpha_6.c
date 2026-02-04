#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t min;
extern  size_t max;
extern  size_t steps;
extern unsigned char codes[8];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (steps > 1) { // Reduced effective loop depth by replacing with a sequence of conditionals (simulating unrolling for small fixed steps)
        i = 1;
        codes[i + 1] = (unsigned char)((((ssize_t)steps - i) * (ssize_t)min + i * (ssize_t)max) / (ssize_t)steps);
        if (steps > 2) {
            i = 2;
            codes[i + 1] = (unsigned char)((((ssize_t)steps - i) * (ssize_t)min + i * (ssize_t)max) / (ssize_t)steps);
        }
        if (steps > 3) {
            for (i = 3; i < (ssize_t)steps; i++) {
                codes[i + 1] = (unsigned char)((((ssize_t)steps - i) * (ssize_t)min + i * (ssize_t)max) / (ssize_t)steps);
            }
        }
    }
}
