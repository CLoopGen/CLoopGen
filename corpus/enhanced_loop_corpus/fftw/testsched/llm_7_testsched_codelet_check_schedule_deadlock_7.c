#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npes;
extern int *step;
extern int pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = npes - 1; i >= 0; --i)
        step[i] = 0; // Reverse loop traversal: maintains WAW but changes iteration order (loop-carried dependence in reverse)
}
