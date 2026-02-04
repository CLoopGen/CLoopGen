#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < 256; y++) {
    for (x = 0; x < 256; x++) {
        int tab[4] = {0, 2, 3, 1};
        if ((x & 1) || (y & 1)) {
            buffer[0][x + 256 * y] = 256 * 256 * tab[(x & 1) + 2 * (y & 1)];
        } else {
            buffer[0][x + 256 * y] = 0;
        }
    }
}
}
