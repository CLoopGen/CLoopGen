#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[17];
    for (i = 0; i <= 16; i++)
        temp[i] = i * i;
    for (i = 0; i <= 16; i++)
        counts[i] = temp[i];
}
