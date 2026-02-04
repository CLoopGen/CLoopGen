#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned long aa[];
extern unsigned long ran_x[];
extern unsigned int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < 100; j++)
    aa[j] = ran_x[j];

}
