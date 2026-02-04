#include <stdio.h>

#include <inttypes.h>

extern void *buf;
extern unsigned char *cp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_i = i;
    for (size_t j = 0; j < temp_i; j++) {
        cp = (unsigned char *)buf + j;
        *cp ^= 255;
    }
    i = 0; // Ensure i is decremented to 0 as in original
}
