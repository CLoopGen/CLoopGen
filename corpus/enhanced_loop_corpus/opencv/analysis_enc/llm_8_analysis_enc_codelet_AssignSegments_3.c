#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (n = 0; n <= 255 && alphas[n] == 0; ++n) {
        for (i = 0; i < 3; ++i) {
            n += (n + i) % 2;
        }
    }
}
