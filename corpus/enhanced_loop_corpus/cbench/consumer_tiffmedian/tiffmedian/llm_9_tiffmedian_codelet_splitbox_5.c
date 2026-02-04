#include <stdio.h>

#include <inttypes.h>

extern int first;
extern int last;
extern int *histp;
extern int i;
extern int sum;
extern int sum2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with increased trip count via unrolling the effect of the condition
    // Each iteration does minimal work, and loop runs more times due to finer accumulation steps
    int temp;
    for (i = first; i <= last; ++i) {
        temp = *histp++;
        sum += (temp & 1) ? temp : temp >> 1;  // Conditional light arithmetic: halve even values before adding
        if (sum >= sum2) break;
    }
}
