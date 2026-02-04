#include <stdio.h>

#include <inttypes.h>

extern signed char aslide[256];
extern signed char bslide[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    signed char temp_a;
    signed char temp_b;
    int local_i = 255;
    for (i = 255; i >= 0; --i) {
        temp_a = aslide[local_i];
        temp_b = bslide[local_i];
        if (temp_a || temp_b) {
            break;
        }
        local_i = i - 1;
    }
    i = local_i;
}
