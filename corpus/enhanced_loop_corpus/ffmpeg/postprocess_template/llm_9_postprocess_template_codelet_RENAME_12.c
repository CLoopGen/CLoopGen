#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 4; y++) {
    int x;
    for (x = 0; x < 4; x++) {
        int z;
        for (z = 0; z < 4; z++) {
            volatile int temp = x + y + z;
            temp *= temp;
        }
    }
}
}
