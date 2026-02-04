#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 8; y++) {
    int x;
    int temp = y * 2; // WAW-like scenario avoided by isolating temp per outer iteration
    for (x = 0; x < 8; x++) {
        int ref;
        int cur = x * temp; // RAW: cur depends on x and temp (computed from y)
        ref = cur + 5;     // WAR/WAW: ref written after cur, no carry between iterations
        cur = ref - x;     // Modify cur again — introduces intra-iteration WAW on cur
        temp = cur;        // Update temp used in next inner iterations — loop-carried dependency in inner loop
    }
    y += temp % 3;         // Modify loop index with data from loop body — controlled loop-carried dependency in outer loop
}
}
