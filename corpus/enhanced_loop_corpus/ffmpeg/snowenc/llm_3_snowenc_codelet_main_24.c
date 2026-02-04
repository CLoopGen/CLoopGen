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
        int val0 = 65536 * tab[0]; // (x&1)=0, (y&1)=0 -> index 0
        int val1 = 65536 * tab[2]; // (x&1)=0, (y&1)=1 -> index 2
        int val2 = 65536 * tab[1]; // (x&1)=1, (y&1)=0 -> index 1
        int val3 = 65536 * tab[3]; // (x&1)=1, (y&1)=1 -> index 3
        
        buffer[0][x + 256 * y]       = val0;
        buffer[0][x + 1 + 256 * y]   = val2;
        buffer[0][x + 256 * (y + 1)] = val1;
        buffer[0][x + 1 + 256 * (y + 1)] = val3;
    }
}
}
