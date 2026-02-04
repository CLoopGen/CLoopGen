#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_pixels;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < num_pixels * 3; i += 3) {
        j = i + 1;
        j *= 2;
        j -= 1;
    }
}
