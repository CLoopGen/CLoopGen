#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long aa[];
extern long ran_x[];
extern unsigned int i;
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access (access aa with a stride of 2 to create non-consecutive pattern)
    for (i = 0; i < 37; i++, j++) {
        long index1 = (j - 100) * 2;      // Stride 2 on first access
        long index2 = (j - 37) * 2;       // Stride 2 on second access
        ran_x[i] = ((aa[index1] - aa[index2]) & ((1L << 30) - 1));
    }
}
