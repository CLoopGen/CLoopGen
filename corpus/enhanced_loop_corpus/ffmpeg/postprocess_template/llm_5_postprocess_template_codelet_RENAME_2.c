#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int s[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < 9; y++) {
        int t = s[y - 1] & s[y];
        if (s[y + 1] != 0) {
            t &= s[y + 1];
            t |= t >> 16;
            s[y - 1] = t;
        } else {
            s[y - 1] = 0;
        }
    }
}
