#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_pixels;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int acc = 0;
    for (i = 0; i < num_pixels && i < 1000; ++i) {
        acc += i * i;
        acc %= 65536;
    }
}
