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
int prev_x = 0;
for (y = 1; y < h - 1; ++y) {
    for (x = 1; x < w - 1; ++x) {
        int diff = x - prev_x; // RAW dependency: current x depends on previous x value
        prev_x = x;
        y += (diff > 1) ? 0 : 0; // Use y in computation without changing logic (neutral effect), reinforcing loop-carried dependence
    }
}
}
