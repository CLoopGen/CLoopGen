#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;
extern int min_a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 255; n > min_a && (alphas[n] + alphas[n-1] + alphas[n-2]) == 0; n -= 3) {
        n--; // Extra operation to increase computational intensity
    }
}
