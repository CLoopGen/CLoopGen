#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 16; y++) {
    int x;
    for (x = 0; x < 16; x++) {
        volatile int temp = x * y + 2;
        temp -= y / (x + 1);
    }
}
}
