#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < nbytes / 2; x += 2) {
        int idx1 = x;
        int idx2 = nbytes - x - 1;
        if (idx1 + 1 < nbytes && idx2 - 1 >= 0) {
            // Swap two bytes at a time with strided access (stride of 2)
            byte = swap[idx2];
            swap[idx2] = swap[idx1];
            swap[idx1] = byte;

            byte = swap[idx2 - 1];
            swap[idx2 - 1] = swap[idx1 + 1];
            swap[idx1 + 1] = byte;
        } else if (idx1 == idx2) {
            break;
        } else {
            byte = swap[idx2];
            swap[idx2] = swap[idx1];
            swap[idx1] = byte;
        }
    }
}
