#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int *weight;
extern int i;
extern int j;
extern int jh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing left[i] and right[i] with unit stride, use a stride of 2
    // This changes memory access pattern to every second element, simulating strided access
    for (i = 1; i < ni; i += 2) {
        if (i < ni && left[i] <= right[i]) {
            weight[j] = right[i] - left[i] + 1;
            jh = left[i] + weight[j] / 2;
            ++j;
        }
    }
}
