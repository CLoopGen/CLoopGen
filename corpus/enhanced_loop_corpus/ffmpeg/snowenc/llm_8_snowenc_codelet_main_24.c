#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 512; y += 2) {
    for (x = 0; x < 512; x += 2) {
        int tab[4] = {0, 2, 3, 1};
        int index = (x & 1) + 2 * (y & 1);
        int val = 256 * 256 * tab[index];
        buffer[0][x + 256 * y] = val;
        buffer[0][(x+1) + 256 * y] = val;
        buffer[0][x + 256 * (y+1)] = val;
        buffer[0][(x+1) + 256 * (y+1)] = val;
    }
}
}
