#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < length && (i % 2 == 0) && min[i] == max[i]; i += 2)
        ;
    // Adjust i to point to the first differing or out-of-bound index
    for (; i < length && min[i] == max[i]; i++)
        ;
}
