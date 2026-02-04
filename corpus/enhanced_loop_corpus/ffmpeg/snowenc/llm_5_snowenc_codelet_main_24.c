#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 256; y += 2) {
    for (x = 0; x < 256; x += 2) {
        int tab[4] = {0, 2, 3, 1};
        // Process 2x2 block at once without branching
        buffer[0][x + 256 * y]           = 256 * 256 * tab[0];         // (even, even)
        buffer[0][(x+1) + 256 * y]       = 256 * 256 * tab[2];         // (odd, even)
        buffer[0][x + 256 * (y+1)]       = 256 * 256 * tab[1];         // (even, odd)
        buffer[0][(x+1) + 256 * (y+1)]   = 256 * 256 * tab[3];         // (odd, odd)
    }
}
}
