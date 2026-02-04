#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;
extern int min_a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (n = 255; n > min_a && !found; --n) {
        found = (alphas[n] != 0);
    }
    if (n <= min_a) {
        n = min_a;
    } else {
        n++;
    }
}
