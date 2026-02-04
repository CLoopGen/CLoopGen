#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y += 2) {
        const int *const clip_table = (const int *const)&x;
        for (x = 1; x <= 8; x <<= 1) {
            volatile int temp = x * y + 3;
            temp -= (temp % (y + 1 + (y == 0)));
        }
    }
}
