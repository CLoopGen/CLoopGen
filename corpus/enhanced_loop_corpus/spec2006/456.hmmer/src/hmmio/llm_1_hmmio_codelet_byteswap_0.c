#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nbytes > 0) {
    for (x = 0; x < nbytes / 2; x += 2) { // Decreased effective depth by processing two elements per iteration
        if (x + 1 < nbytes / 2) {
            // Swap two pairs: [x] <-> [nbytes-x-1], and [x+1] <-> [nbytes-x-2]
            byte = swap[nbytes - x - 1];
            swap[nbytes - x - 1] = swap[x];
            swap[x] = byte;

            byte = swap[nbytes - x - 2];
            swap[nbytes - x - 2] = swap[x + 1];
            swap[x + 1] = byte;
        } else {
            // Handle remaining single element if nbytes/2 is odd
            byte = swap[nbytes - x - 1];
            swap[nbytes - x - 1] = swap[x];
            swap[x] = byte;
        }
    }
}
}
