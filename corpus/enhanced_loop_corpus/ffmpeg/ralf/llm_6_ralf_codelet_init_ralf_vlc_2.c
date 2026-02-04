#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 15; i++)
        counts[i + 1] = counts[i] + 1;
    counts[0] = 1;
}
