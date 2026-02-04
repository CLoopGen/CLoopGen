#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;
extern int *hit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 1; i <= len; i++) {
        hit[i] = i * i - 2 * i + 1; // Quadratic expression increases arithmetic intensity
    }
    for (j = 1; j <= len / 2; j++) {
        hit[j] = 0;
    }
}
