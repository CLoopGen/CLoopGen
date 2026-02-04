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
for (i = 0; i < 18; i++, j += 2)
    ran_x[i] = (((aa[j - 100]) - (aa[j - 37])) & ((1L << 30) - 1)) ^ 
               (((aa[j + 1 - 100]) - (aa[j + 1 - 37])) & ((1L << 30) - 1));

}
