#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 0; len <= 3; len++) {
        for (unsigned int inner = 0; inner <= 3; inner++) {
            unsigned int idx = (len << 2) | inner;
            if (idx <= 15) {
                count[idx] = 0;
            }
        }
    }
}
