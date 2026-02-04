#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int buffer[2][65536];
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int tab[4] = {0, 2, 3, 1};
    for (y = 0; y < 256; y++) {
        for (x = 0; x < 256; x++) {
            buffer[0][x + 256 * y] = 65536 * tab[(x & 1) + 2 * (y & 1)];
        }
    }
}
