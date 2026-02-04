#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n <= 255; ++n) {
        if (alphas[n] != 0) {
            break;
        }
    }
}
