#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int s[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 2; y < 8; y += 2) {
    int t = s[y - 2] & s[y - 1] & s[y] & s[y + 1] & s[y + 2];
    t |= t >> 8;
    t |= t >> 16;
    s[y - 2] = t;
}
}
