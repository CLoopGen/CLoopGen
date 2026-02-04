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
        int index = (x & 1) + 2 * (y & 1);
        buffer[0][x + 256 * y] = 256 * 256 * tab[index];
        // Introduce a WAW dependency by writing to same location in different iterations
        if ((x + y) % 256 == 0 && y > 0) {
            buffer[0][x] = buffer[0][x + 256 * (y - 1)]; // Write-after-write: buffer[0][x] depends on prior write
        }
    }
}
}
