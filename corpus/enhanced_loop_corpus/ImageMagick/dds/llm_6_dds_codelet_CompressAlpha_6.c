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
    ssize_t temp[8] = {0};
    for (i = 1; i < (ssize_t)steps; i++) {
        temp[i + 1] = ((ssize_t)steps - i) * (ssize_t)min + i * (ssize_t)max;
    }
    for (i = 1; i < (ssize_t)steps; i++) {
        codes[i + 1] = (unsigned char)(temp[i + 1] / (ssize_t)steps);
    }
}
