#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
for (x = 0; x < nbytes / 2; x += step) {
    byte = swap[nbytes - x - 1];
    swap[nbytes - x - 1] = swap[x];
    swap[x] = byte;
    if (x + 1 < nbytes / 2) {
        byte = swap[nbytes - x - 2];
        swap[nbytes - x - 2] = swap[x + 1];
        swap[x + 1] = byte;
    }
}
}
