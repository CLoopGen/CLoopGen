#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    for (x = 0; x < nbytes / 2; x++) {
        temp = swap[x];
        swap[x] = swap[nbytes - x - 1];
        // Introduce a WAW dependency by writing to same location twice (redundant but creates loop-carried WAW)
        swap[x] = temp;
        swap[nbytes - x - 1] = temp;
    }
}
