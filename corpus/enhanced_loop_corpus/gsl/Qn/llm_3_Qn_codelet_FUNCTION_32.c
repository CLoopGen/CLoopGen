#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    // Iterates from the end of the array to the beginning to reverse access order
    for (i = ni - 1; i >= 0; --i) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
}
