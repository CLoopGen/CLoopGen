#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 1;
    for (h = 1; h < x; h = temp, temp = temp * 2)
        ;
}
