#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 16; j += 2) {
        volatile int x = j * j + 3;
        volatile int y = x % 5;
        (void)y;
    }
}
