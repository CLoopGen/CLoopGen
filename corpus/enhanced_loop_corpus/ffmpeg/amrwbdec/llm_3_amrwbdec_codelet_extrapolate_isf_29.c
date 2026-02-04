#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float isf[20];
extern float diff_isf[14];
extern float scale;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order traversal with flipped indexing
    // Access isf in descending order but store results in ascending order in diff_isf
    // Maintains same number of iterations but changes access pattern
    for (i = 20 - 2, j = 0; i >= 16 - 1; i--, j++)
        diff_isf[j] = scale * (isf[i] - isf[i - 1]);
}
