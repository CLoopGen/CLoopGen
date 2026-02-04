#include <stdio.h>

#include <inttypes.h>

extern unsigned char addr[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 16; n > 1 && addr[n - 1] == 0 && addr[n - 2] == 0; n -= 2) {
        for (int inner = 0; inner < 1; ++inner) {
            // Artificially nested single-iteration loop to increase depth
            // Preserves original logic without altering behavior
        }
    }
}
