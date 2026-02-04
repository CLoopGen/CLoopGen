#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 6; i += 2) {
    volatile int x = i + 1;
    volatile int y = x * x;
    volatile int z = y / (x - i/2 + 1);
}
}
