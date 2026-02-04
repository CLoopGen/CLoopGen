#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (len = 1; len < 15; len += 2) {
        offs[len + 1] = offs[len] + count[len];
        if (len + 1 < 14) {
            offs[len + 2] = offs[len + 1] + count[len + 1];
        }
    }
}
