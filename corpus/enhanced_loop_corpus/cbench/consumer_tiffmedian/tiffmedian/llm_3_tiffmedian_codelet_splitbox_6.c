#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int *histp;
extern int i;
extern int j;
extern int sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access with index offset, using array notation
    int *temp = histp + (first % 4);  // Introduce alignment-like offset
    for (sum1 = 0, j = 0; j < (i - first); j++)
        sum1 += temp[j];
}
