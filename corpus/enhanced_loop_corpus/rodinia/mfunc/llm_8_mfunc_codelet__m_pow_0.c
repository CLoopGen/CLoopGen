#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int p;
extern int max_bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = p;
    for (max_bit = 0; temp != 0; max_bit++)
        temp >>= 1;
}
