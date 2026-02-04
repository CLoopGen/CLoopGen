#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (n = 0; n <= 255 && alphas[n] == 0; n += step) {
        step = (alphas[(n + 1) % 256] == 0) ? 1 : 2;
    }
}
