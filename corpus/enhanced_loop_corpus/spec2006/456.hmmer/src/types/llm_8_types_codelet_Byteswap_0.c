#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < nbytes; i += 2) {
        if (i >= nbytes - i - 1) break;
        byte = swap[nbytes - i - 1];
        swap[nbytes - i - 1] = swap[i];
        swap[i] = byte;
    }
}
