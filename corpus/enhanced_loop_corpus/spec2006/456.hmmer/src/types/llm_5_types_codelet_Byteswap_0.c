#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < nbytes / 2; x++) {
    if (swap[x] == swap[nbytes - x - 1]) {
        continue;
    }
    byte = swap[nbytes - x - 1];
    swap[nbytes - x - 1] = swap[x];
    swap[x] = byte;
}
}
