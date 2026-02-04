#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    n = 0;
    for (; n <= 255 && (alphas[n] == 0 ? 1 : 0); ++n) {
    }
}
