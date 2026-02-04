#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int s[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 1; y < 10; y++) {
    int t1 = s[y % 10] & s[(y + 1) % 10];
    int t2 = s[(y + 2) % 10] & s[(y + 3) % 10];
    int t = t1 & t2;
    t |= t >> 16;
    t ^= t >> 8;
    s[y % 10] = t;
}
}
