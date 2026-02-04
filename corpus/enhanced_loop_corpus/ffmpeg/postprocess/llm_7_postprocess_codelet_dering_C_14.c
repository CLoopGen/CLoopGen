#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int s[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp[8];
for (y = 1; y < 9; y++) {
    int t = s[y - 1] & s[y] & s[y + 1];
    t |= t >> 16;
    temp[y - 1] = t;
}
for (y = 1; y < 9; y++) {
    s[y - 1] = temp[y - 1];
}
}
