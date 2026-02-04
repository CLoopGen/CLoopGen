#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;
extern int min_a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    n = 255;
    for (i = 255; i > min_a; --i) {
        if (alphas[i] != 0) {
            n = i;
            break;
        }
        n = i - 1;
    }
}
