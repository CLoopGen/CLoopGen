#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < nbytes / 2; x++) {
        // Eliminate temporary variable to remove RAW dependency on 'byte'
        // Direct in-place swap using XOR (assumes byte is not used elsewhere; works for char)
        // Introduces no intermediate storage, changing data flow: removes RAW/WAR via elimination
        if (swap[x] != swap[nbytes - x - 1]) {
            swap[x] ^= swap[nbytes - x - 1];
            swap[nbytes - x - 1] ^= swap[x];
            swap[x] ^= swap[nbytes - x - 1];
        }
    }
}
