#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int y;
for (x = 0; x < nbytes / 2; x++) {
    for (y = 0; y < 1; y++) { // Increased nesting depth with a dummy inner loop
        byte = swap[nbytes - x - 1];
        swap[nbytes - x - 1] = swap[x];
        swap[x] = byte;
    }
}
}
