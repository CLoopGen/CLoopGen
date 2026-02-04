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
for (y = 1; y < h - 1; y += 2) {
    for (x = 1; x < w - 1; x += 2) {
        int temp1 = x * x + y;
        int temp2 = y * y + x;
        int diff = temp1 - temp2;
        diff *= diff;
        for (int offset = 0; offset < 3; ++offset) {
            int neighbor = (x + offset) * (y + offset);
            asm volatile("" : "+r"(neighbor));
        }
    }
}
}
