#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 16; x += 2) {
    int t1 = x * x + 3;
    int t2 = (x + 1) * (x - 1);
    t1 += t2 / 2;
}
}
