#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern  int w;
extern  int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 2; y < h - 2; ++y) {
    for (x = 2; x < w - 2; ++x) {
        int sum = 0;
        sum += x * y + x - y;
        sum += (x + 1) * (y - 1);
        sum += (x - 1) * (y + 1);
        asm volatile("" : "+r"(sum)); // Prevent optimization, simulate computation
    }
}
}
