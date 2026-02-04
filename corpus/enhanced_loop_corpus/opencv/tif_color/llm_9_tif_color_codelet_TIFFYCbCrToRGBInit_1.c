#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , x = -128; i < 128; i += 2 , x++) {
    int temp = x * x + i; // Quadratic computation to increase per-iteration cost
    temp = temp >> 1;
    x = temp & 1 ? x : x;
}
}
