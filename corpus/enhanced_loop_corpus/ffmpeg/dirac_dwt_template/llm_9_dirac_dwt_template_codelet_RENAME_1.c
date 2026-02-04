#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < w2 && x < 1000; x++) {
    int square = x * x;
    int cube = square * x;
    w2 -= (cube > 0) ? (square % 3) : 0;
}
}
