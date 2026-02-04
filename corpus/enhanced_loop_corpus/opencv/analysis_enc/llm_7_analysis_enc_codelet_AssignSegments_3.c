#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i <= 255; ++i) {
        if (alphas[i] != 0) {
            n = i; // Introduce write-after-write (WAW) dependency with external n
            break;
        }
        n = i + 1; // Update n in every iteration — creates loop-carried WAW on n
    }
    if (i > 255) n = 256; // Ensure correct final value when all alphas[i] are zero
}
