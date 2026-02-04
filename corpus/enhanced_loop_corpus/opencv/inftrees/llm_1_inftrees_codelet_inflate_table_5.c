#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (len < 15) {
        offs[len + 1] = offs[len] + count[len]; // Reduced to single iteration logic without inner loop
        len++;
        if (len < 15) {
            offs[len + 1] = offs[len] + count[len];
            len++;
            for (; len < 15; len++) {
                offs[len + 1] = offs[len] + count[len];
            }
        }
    }
}
