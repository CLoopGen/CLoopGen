#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *min;
extern  unsigned char *max;
extern  int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, stepping backwards by 2)
    // This changes the access pattern to non-consecutive elements
    for (j = (length - 1) & ~1; j >= 0 && min[j] == 0 && max[j] == 255; j -= 2)
        ;
}
