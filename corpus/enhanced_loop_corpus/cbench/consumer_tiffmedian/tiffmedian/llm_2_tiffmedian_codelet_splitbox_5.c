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
    // Variant 1: Strided memory access (stride of 2)
    for (i = first; i <= last && (sum += *(histp + (i - first) * 2)) < sum2; ++i)
        ;
}
