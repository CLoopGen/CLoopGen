#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM temp;
    for (y = block_h * mb_y; y < ((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)); y++) {
        temp = buf[y * w]; // Introduce WAW and WAR dependency by reusing temp across iterations
        for (x = 0; x < w; x++) {
            temp = buf[x + y * w] - (128 << 4);
            buf[x + y * w] = temp; // Create loop-carried dependence on temp (RAW within row)
        }
        // Final dummy use to enforce dependence on last temp value (simulated artificial carry)
        if (y == (((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)) - 1)) {
            buf[0] += (temp - temp); // No-op but preserves data dependency chain
        }
    }
}
