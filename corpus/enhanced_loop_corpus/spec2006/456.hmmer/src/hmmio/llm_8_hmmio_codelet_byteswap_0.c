#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < nbytes; i++) {
    if (i < nbytes / 2) {
        byte = swap[nbytes - i - 1];
        swap[nbytes - i - 1] = swap[i];
        swap[i] = byte;
    }
}
}
