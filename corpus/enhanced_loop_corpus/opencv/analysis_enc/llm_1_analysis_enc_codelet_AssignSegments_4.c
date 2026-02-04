#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;
extern int min_a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 1; ++outer) {
    for (int middle = 0; middle < 1; ++middle) {
        for (n = 255; n > min_a && alphas[n] == 0; --n) {
        }
    }
}
}
